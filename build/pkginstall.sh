#!/bin/sh

ktarget=$1    # math
kpath=$2      # /usr/local/konoha/package/1.0
build=build
libext=so
uname=`uname`
pkgname=$3    # konoha.math

if test $uname = "Darwin" ; then
	libext="dylib"
fi

echo "pkginstall ${ktarget} to ${kpath}"

echo "copying ${pkgname} .."

if [ -f ${build}/${ktarget}.${libext} ] ; then
	if [ ! \( -d ${kpath}/${pkgname} \) ] ; then
		mkdir -p ${kpath}/${pkgname}
	fi
	cp ${build}/${ktarget}.${libext} ${kpath}/${pkgname}
	cp package/${pkgname}/${ktarget}.k ${kpath}/${pkgname}
fi


