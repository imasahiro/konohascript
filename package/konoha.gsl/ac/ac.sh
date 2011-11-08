#!/bin/sh

PKGDIR="."

echo ... start $PKGDIR/ac/${0##*/} ...

logfile=ac.log

if [ -e $PKGDIR/$logfile ] ;then
	rm $PKGDIR/$logfile
fi

for utest in `find $PKGDIR/ac -name "*.k"`; do
    echo $utest
    konoha -l "+$PKGDIR/$logfile" $utest
done


echo ... all tests were done ...
