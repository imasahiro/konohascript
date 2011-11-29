#!/bin/sh

PKGDIR="."

echo ... start memcached ...
memcached -d
memcached -d -p 11212

echo ... start $PKGDIR/ac/${0##*/} ...

logfile=ac.log

if [ -e $PKGDIR/ac/$logfile ] ;then
	rm $PKGDIR/ac/$logfile
fi

for utest in `find $PKGDIR/ac -name "*.k"`; do
    echo $utest
    konoha -l "+$PKGDIR/ac/$logfile" $utest
done

killall memcached
echo ... all tests were done ...
