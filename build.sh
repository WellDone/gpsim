#!/bin/bash
set -e

#Get the directory this script is in
#From http://stackoverflow.com/questions/59895/can-a-bash-script-tell-what-directory-its-stored-in
BASEDIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
SRCDIR="$BASEDIR/src"
GPSIMBUILDDIR="$BASEDIR/build"
OUTDIR="$BASEDIR/out"

#SVN_URL="svn://svn.code.sf.net/p/gpsim/code/trunk"
OLDDIR=`pwd`

#Programs that we need
LIBTOOL="libtoolize"

function usage {
	echo "Usage: build.sh [link|configure|make|clean|package]"
	exit 1
}

function link_gpsim {
	mkdir -p $GPSIMBUILDDIR
	cd "$GPSIMBUILDDIR"
	echo "Linking src directory to build directory."
	find $SRCDIR -mindepth 1 -depth -type d -printf "%P\n" | while read dir; do mkdir -p "$dir"; done
	find $SRCDIR -type f -printf "%P\n" | while read file; do ln -sf "$SRCDIR/$file" "$file"; done
}

function configure_gpsim {
	#rm -rf $GPSIMBUILDDIR
	./build.sh link

	rm -rf $GPSIMBUILDDIR/m4
	cp -prf $SRCDIR/m4 $GPSIMBUILDDIR/

	cd "$GPSIMBUILDDIR"

	autoreconf --install --force
	./configure --prefix="$OUTDIR" --disable-gui
	cd ..
}

function make_gpsim {
	cd "$GPSIMBUILDDIR"
	make "$@"
	make install
	cd ..
}

function clean_gpsim {
	rm -rf "$GPSIMBUILDDIR"
	cd "$GPSIMBUILDDIR"
	make clean > /dev/null 2>&1
	rm -rf "$OUTDIR"
	cd ..
}

function package_gpsim {
	cd $OUTDIR && tar czf $BASEDIR/gpsim.tar.gz ./*
}

#Process Options
if (($#==0)); then
	usage
fi

cd "$BASEDIR"
if [ ! -d $GPSIMBUILDDIR ]; then
	mkdir "$GPSIMBUILDDIR"
fi

if [ ! -d $OUTDIR ]; then
	mkdir "$OUTDIR"
fi


task="$1"
shift
case $task in
	link)
	link_gpsim
	;;

	configure)
	configure_gpsim
	;;

	make)
	make_gpsim
	;;

	clean)
	clean_gpsim
	;;

	package)
	package_gpsim
	;;

	*)
	usage
	;;
esac

cd "$OLDDIR"
exit 0