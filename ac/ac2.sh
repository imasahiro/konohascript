#!/bin/bash

logfile="`uname -s`-`uname -r`-`konoha -V0`.txt"

echo "[os] `uname -a`" >> $logfile
find ./ac -maxdepth 2 -name '*.k' | while read utest; do
	echo "Testing $utest .."
	konoha -l "+$logfile" $utest || echo "[SEGV] FAILED $utest" >> $logfile
done

egrep -i "\] FAILED" $logfile
echo "see furthermore information in $logfile"
egrep -i "\] FAILED" $logfile | wc -l

