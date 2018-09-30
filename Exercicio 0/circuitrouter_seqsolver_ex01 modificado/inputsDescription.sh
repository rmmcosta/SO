#!/bin/bash

for f in $(ls inputs/*.txt)
do
    #echo $(wc -l $f) $(wc -w $f)
    lines="lines:$(wc -l $f)"
    ps="interconnections:$(grep -o p $f | wc -l)"
    echo $lines $words $ps | xargs -n1 | sort -u | xargs
done