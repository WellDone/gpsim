#!/bin/bash

#Get the directory this script is in
#From http://stackoverflow.com/questions/59895/can-a-bash-script-tell-what-directory-its-stored-in
BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
BUILDDIR="$BASEDIR/build"

PATCHFILE="$BASEDIR/gpsim_momo_patch.diff"
SVN_URL="svn://svn.code.sf.net/p/gpsim/code/trunk"
GPSIMDIR="gpsim"

OLDDIR=`pwd`

#Programs that we need
LIBTOOL="libtoolize"

#Return 0 if svn has not been checked out 
#Return 1 if svn has been checked out
function svn_checkedout() {
	svn status gpsim 2>&1 | grep W155007 > /dev/null
}

#Check if the svn repository is a clean checkout, indicating our patch has not been applied
#Return 0 if the patch has been applied
#Return 1 if the patch has not been applied
function patch_applied() {
	svn status gpsim 2>&1 | grep ^M > /dev/null
}

function update_svn {
	#Make sure gpsim code has been checked out
	svn_checkedout
	if (($?==0)); then
		echo -n "Checking out GPSIM from SVN (this could take a few minutes)..."
		svn checkout $SVN_URL > /dev/null gpsim
		echo "	DONE"
	fi

	patch_applied
	if (($?==1)); then
		echo "Patching GPSIM Code..."
		patch -p0 < "$PATCHFILE" -d "$GPSIMDIR" > /dev/null
		echo "DONE Patching."
	fi
}

function usage {
	echo "Usage: build.sh [configure|make|clean]"
	exit 1
}

function configure_gpsim {
	cd "$GPSIMDIR"
	$LIBTOOL --force
	aclocal
	autoheader
	automake --force-missing --add-missing
	autoconf
	./configure --prefix="$BUILDDIR" --disable-gui
	cd ..
}

function make_gpsim {
	cd "$GPSIMDIR"
	make "$@"
	make install
	cd ..
}

function clean_gpsim {
	cd "$GPSIMDIR"
	make clean > /dev/null 2>&1
	svn st | grep '^?' | awk '{print $2}' | xargs rm -rf
	svn revert -R .
	cd ..
}

#Process Options
if (($#==0)); then
	usage
fi

cd "$BASEDIR"
if [ ! -d $GPSIMDIR ]; then
	mkdir "$GPSIMDIR"
fi

if [ ! -d $BUILDDIR ]; then
	mkdir "$BUILDDIR"
fi


task="$1"
shift
case $task in
	configure)
	update_svn
	configure_gpsim
	;;

	make)
	update_svn
	make_gpsim
	;;

	clean)
	clean_gpsim
	;;

	*)
	usage
	;;
esac

cd "$OLDDIR"
exit 0