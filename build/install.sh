#!/bin/sh

ktarget=konoha1
kpath=/usr/local
build=build
libext=so
uname=`uname`

if test $uname = "Darwin" ; then
	libext="dylib"
fi

echo "install ${ktarget} to ${kpath}"

if [ ! \( -d ${kpath} \) ] ; then
	echo "setup ${kpath}"
	mkdir ${kpath}
	mkdir ${kpath}/bin
	mkdir ${kpath}/lib
	mkdir ${kpath}/include
fi

if [ ! \( -d ${kpath}/include/${ktarget} \) ] ; then
	mkdir ${kpath}/include/${ktarget}
fi

echo "copying.."

cp ${build}/${ktarget} ${kpath}/bin/${ktarget}
cp ${build}/lib${ktarget}.${libext} ${kpath}/lib/lib${ktarget}.${libext}
cp include/${ktarget}.h ${kpath}/include/${ktarget}.h
cp include/${ktarget}/*.h ${kpath}/include/${ktarget}

if [ -h ${kpath}/bin/konoha ] ; then
	rm -f ${kpath}/bin/konoha
fi

if [ ! \( -f ${kpath}/bin/konoha \) ] ; then
	ln -s ${kpath}/bin/${ktarget} ${kpath}/bin/konoha
fi

