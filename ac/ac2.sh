#!/bin/bash

logfile="`uname -s`-`uname -r`-`konoha -V0`.txt"

find ./ac -maxdepth 2 -name '*.k' | while read utest; do
	echo "Testing $utest .."
	konoha -l "+$logfile" $utest || echo "[SEGV] $utest" >> $logfile
done

