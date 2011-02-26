#!/bin/sh

ktarget=konoha1
kpath=/usr/local
libext=so
uname=`uname`

if test $uname = "Darwin" ; then
	libext="dylib"
fi

echo "uninstall ${ktarget} from ${kpath}"

if [ -x ${kpath}/bin/${ktarget} ] ; then
	echo "remove executables from ${ktarget}/bin"
	rm -f ${kpath}/bin/${ktarget}
fi

if [ -f ${kpath}/lib/lib${ktarget}.${libext} ] ; then
	echo "remove libraries.. "
	rm -f ${kpath}/bin/lib${ktarget}.${libext}
fi

if [ -d ${kpath}/include/${ktarget} ] ; then
	echo "remove include files.."
	rm -rf ${kpath}/include/${ktarget} ${kpath}/include/${ktarget}.h
fi

