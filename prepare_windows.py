# Script for partially automating the compilation process of gpsim on Windows.
# There are a lot of gotchas in this process, however, that still need to be ironed out.
# I will attempt to list them all out here.
# 1. You need to make sure you have python installed and it needs to have a valid .a file for the python*.dll
#    Follow the instructions here to generate such a file:
#    http://eli.thegreenplace.net/2008/06/28/compiling-python-extensions-with-distutils-and-mingw
# 2. The path to the python installation is currently hardcoded.  You should update it to your location in
#    plat/win32/makefile.mingw
# 3. You must use cygwin (not cygwin64 and you must build a 32 bit binary)
#    build command is make -f makefile.mingw in gpsim base directory

import urllib
import os.path
import shutil
import os
import zipfile
import sys

cygwin = "C:/cygwin"

#All needed packages
reqs = []
reqs.append(['popt-1.8.1', 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/popt-dev-1.10.2-tml-20050828.zip'])
reqs.append(['glib', 'http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib-dev_2.28.8-1_win32.zip'])
reqs.append(['pango', 'http://ftp.gnome.org/pub/gnome/binaries/win32/pango/1.29/pango-dev_1.29.4-1_win32.zip'])
reqs.append(['gtk+', 'http://ftp.gnome.org/pub/gnome/binaries/win32/gtk+/2.24/gtk+-dev_2.24.10-1_win32.zip'])
reqs.append(['atk', 'http://ftp.gnome.org/pub/gnome/binaries/win32/atk/1.32/atk-dev_1.32.0-2_win32.zip'])
reqs.append(['cairo', 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/cairo-dev_1.10.2-2_win32.zip'])
reqs.append(['gdk-pixbuf', 'http://ftp.gnome.org/pub/gnome/binaries/win32/gdk-pixbuf/2.24/gdk-pixbuf-dev_2.24.0-1_win32.zip'])
reqs.append(['fontconfig', 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/fontconfig-dev_2.8.0-2_win32.zip'])
reqs.append(['gtkextra-2', r'http://sourceforge.net/projects/gtkextra/files/2.1.2/gtk%2Bextra-2.1.2-dev.zip'])
reqs.append(['pthreads-src', 'ftp://sourceware.org/pub/pthreads-win32/pthreads-w32-2-9-1-release.zip'])

#All dlls and other files that need to be copied where gpsim.dll is
deps = []
deps.append([('bin/libpopt-0.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/popt-1.10.2-tml-20050828.zip'])
deps.append([('bin/libgthread-2.0-0.dll', 'bin/libgio-2.0-0.dll', 'bin/libglib-2.0-0.dll', 'bin/libgobject-2.0-0.dll', 'bin/libgmodule-2.0-0.dll'), 'http://ftp.gnome.org/pub/gnome/binaries/win32/glib/2.28/glib_2.28.8-1_win32.zip'])
deps.append([(r'bin/*', r'etc/%', r'lib/%'),'http://ftp.gnome.org/pub/gnome/binaries/win32/gtk+/2.24/gtk+_2.24.10-1_win32.zip'])
deps.append([('bin/libpng14-14.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/libpng_1.4.3-1_win32.zip'])
deps.append([(r'etc/%', r'lib/%', 'bin/libpangoft2-1.0-0.dll', 'bin/libpango-1.0-0.dll','bin/libpangowin32-1.0-0.dll', 'bin/libpangocairo-1.0-0.dll'), 'http://ftp.gnome.org/pub/gnome/binaries/win32/pango/1.29/pango_1.29.4-1_win32.zip'])
deps.append([('bin/libatk-1.0-0.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/atk/1.32/atk_1.32.0-2_win32.zip'])
deps.append([('bin/libcairo-2.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/cairo_1.10.2-2_win32.zip'])
deps.append([('bin/libatk-1.0-0.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/atk/1.32/atk_1.32.0-2_win32.zip'])
deps.append([('bin/libgdk_pixbuf-2.0-0.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/gdk-pixbuf/2.24/gdk-pixbuf_2.24.0-1_win32.zip'])
deps.append([('bin/libfontconfig-1.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/fontconfig_2.8.0-2_win32.zip'])
#deps.append(['http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/expat_2.0.1-1_win32.zip'])
deps.append([('bin/iconv.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/libiconv-1.9.1.bin.woe32.zip'])
deps.append([('bin/intl.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/gettext-runtime_0.18.1.1-2_win32.zip'])
deps.append([('bin/zlib1.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/zlib_1.2.5-2_win32.zip'])
deps.append([('bin/freetype6.dll',), 'http://ftp.gnome.org/pub/gnome/binaries/win32/dependencies/freetype_2.4.2-1_win32.zip'])
deps.append([('Pre-built.2/dll/x86/pthreadGC2.dll',), 'ftp://sourceware.org/pub/pthreads-win32/pthreads-w32-2-9-1-release.zip'])
deps.append([('bin/readline5.dll',), 'http://gpsim.sourceforge.net/gpsimWin32/packages/readline-5.2-20061112-bin.zip'])
deps.append([('bin/gtkextra-win32-2.1.dll',), r'http://sourceforge.net/projects/gtkextra/files/2.1.2/gtk%2Bextra-2.1.2-dev.zip'])
deps.append([('bin/popt1.dll',), 'http://downloads.sourceforge.net/project/gnuwin32/popt/1.8-1/popt-1.8-1-bin.zip'])
deps.append([('bin/libintl-2.dll', 'bin/libiconv-2.dll'), 'http://downloads.sourceforge.net/project/gnuwin32/popt/1.8-1/popt-1.8-1-dep.zip'])

def download_file(url, local):
	print "  Downloading %s" % local
	urllib.urlretrieve(url, local)

def extract_package(url, parent, folder=None, extract_only=False):
	if folder is not None:
		print "Preparing %s" % folder
	else:
		print "Fetching %s" % url
	cachedir = os.path.join(parent, "cache")

	if not os.path.exists(cachedir):
		os.mkdir(cachedir)

	base,sep,filename = url.rpartition('/')

	fpath = os.path.join(cachedir, filename)
	if not os.path.exists(fpath):
		download_file(url, fpath)
	else:
		print "  Using cached version"

	if extract_only:
		return fpath

	outdir = os.path.join(parent, folder)
	if os.path.exists(outdir) and not os.path.isdir(outdir):
		raise ValueError("Could not remove folder %s which was not a folder." % outdir)

	if os.path.exists(outdir):
		shutil.rmtree(outdir)

	os.mkdir(outdir)

	fzip = zipfile.ZipFile(fpath)

	fzip.extractall(outdir)

def extract_file(fzip, outdir, f):
	dstfile = os.path.basename(f)
	dstpath = os.path.join(outdir, dstfile)

	fzip.extract(f, outdir)

	#This somehow corrupts the dll files, wtf?
	#with fzip.open(f, 'r') as fileobj:
	#	with open(dstpath, 'w') as destobj:
	#		contents = fileobj.read()
	#		destobj.write(contents)

def copy_runtime(files, archive, parent):
	fpath = extract_package(archive, parent, extract_only=True)
	fzip = zipfile.ZipFile(fpath)

	outdir = os.path.join(parent, 'gpsim', 'gpsim')

	for f in files:
		if '*' in f:
			folder = os.path.dirname(f)
			print '  Extracting everything in folder %s' % folder
			for m in fzip.namelist():
				if m.startswith(folder):
					extract_file(fzip, outdir, m)
		elif '%' in f:
			folder = os.path.dirname(f)
			print '  Extracting folder %s' % folder
			
			for m in fzip.namelist():
				if m.startswith(folder):
					fzip.extract(m, outdir)
		else:
			try:
				print "  Extracting %s" % f
				extract_file(fzip, outdir, f)
			except KeyError:
				print fzip.namelist()
				print "Could not extract %s" % f
				sys.exit(1)

#Start of script
if len(sys.argv) != 3:
	print "usage: prepare_windows.py [prepare|package] <desired project directory>"
	sys.exit(1)

cmd = sys.argv[1]
if cmd not in ['prepare', 'package']:
	print "usage: prepare_windows.py [prepare|package] <desired project directory>"
	sys.exit(1)

basedir = sys.argv[2]
if not os.path.exists(basedir):
	os.mkdir(basedir)

if cmd == 'prepare':
	for folder, url in reqs:
		extract_package(url, basedir, folder)

	#Copy over the source code
	srcdir = os.path.join(os.path.dirname(__file__), 'src')
	dstdir = os.path.join(basedir, 'gpsim')
	if os.path.exists(dstdir):
		shutil.rmtree(dstdir)

	print "Copying source code"
	shutil.copytree(srcdir, dstdir)

	print "Unpacking pthreads"
	if os.path.exists(os.path.join(basedir, 'pthreads')):
		shutil.rmtree(os.path.join(basedir, 'pthreads'))

	shutil.copytree(os.path.join(basedir, 'pthreads-src', 'Pre-built.2', 'lib', 'x86'), os.path.join(basedir, 'pthreads', 'lib'))
	shutil.copytree(os.path.join(basedir, 'pthreads-src', 'Pre-built.2', 'dll', 'x86'), os.path.join(basedir, 'pthreads', 'dll'))
	shutil.copytree(os.path.join(basedir, 'pthreads-src', 'Pre-built.2', 'include'), os.path.join(basedir, 'pthreads', 'include'))
elif cmd == 'package':
	for files, archive in deps:
		copy_runtime(files, archive, basedir)

	print "Copying gpsim executable"
	src = os.path.join(basedir, 'gpsim', 'gpsim', 'gpsim.exe')
	dst = os.path.join(basedir, 'gpsim', 'gpsim', 'bin', 'gpsim.exe')
	shutil.copyfile(src, dst)

	print "Copying gpsim dll"
	src = os.path.join(basedir, 'gpsim', 'src', 'libgpsim.dll')
	dst = os.path.join(basedir, 'gpsim', 'gpsim', 'bin', 'libgpsim.dll')
	shutil.copyfile(src, dst)

	print "Copying gcc runtime"
	src = os.path.join(cygwin, 'usr', 'i686-w64-mingw32', 'sys-root', 'mingw', 'bin', 'libgcc_s_sjlj-1.dll')
	dst = os.path.join(basedir, 'gpsim', 'gpsim', 'bin', 'libgcc_s_sjlj-1.dll')
	shutil.copyfile(src, dst)

	src = os.path.join(cygwin, 'usr', 'i686-w64-mingw32', 'sys-root', 'mingw', 'bin', 'libstdc++-6.dll')
	dst = os.path.join(basedir, 'gpsim', 'gpsim', 'bin', 'libstdc++-6.dll')
	shutil.copyfile(src, dst)

	print "Copying gpsim modules"
	src = os.path.join(basedir, 'gpsim', 'modules', 'libgpsim_modules.dll')
	dst = os.path.join(basedir, 'gpsim', 'gpsim', 'bin', 'libgpsim_modules.dll')
	shutil.copyfile(src, dst)