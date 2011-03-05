#!/bin/sh

ktarget=konoha1
kpath=/usr/local
build=build
libext=so
uname=`uname`

if test $uname = "Darwin" ; then
	libext="dylib"
fi

if [ ! -z $1 ] ; then
	ktarget=$1
fi

if [ ! -z $2 ] ; then
	kpath=$2
fi

echo "install ${ktarget} to ${kpath}"
echo "copying.."

install -D -m 755 ${build}/${ktarget} ${kpath}/bin/${ktarget}
install -D -m 644 ${build}/lib${ktarget}.${libext} ${kpath}/lib/lib${ktarget}.${libext}
install -D -m 644 include/${ktarget}.h ${kpath}/include/${ktarget}.h
install -d ${kpath}/include/${ktarget}
cp include/${ktarget}/*.h ${kpath}/include/${ktarget}

if [ -h ${kpath}/bin/konoha ] ; then
	rm -f ${kpath}/bin/konoha
fi

if [ ! \( -f ${kpath}/bin/konoha \) ] ; then
	ln -s ${kpath}/bin/${ktarget} ${kpath}/bin/konoha
fi

