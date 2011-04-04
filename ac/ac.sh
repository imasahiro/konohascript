#!/bin/bash

export UTEST="./ac/AssuraceCases"

find ./ac -maxdepth 2 -name '*.k' | while read utest; do
	echo $utest
	konoha --utest $utest
done

