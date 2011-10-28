#!/bin/sh

out=operator.diff.c

for c in `find src -name '*.c'`; do
    if [ $c != 'src/mpikonoha.c' ]; then
        cat $c >> $out
    fi
done
