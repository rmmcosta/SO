#!/bin/bash

for f in $(ls inputs/*.txt)
do
    #echo $(wc -l $f) $(wc -w $f)
    lines="lines:$(wc -l $f)"
    #the pipe passes the left output to the right input
    ps="interconnections:$(grep -o p $f | wc -l)"
    #sort -u -> sort and removes duplicates
    #-n1 use at most 1 argument per command line
    echo $lines $ps | xargs -n1 | sort -u | xargs
    #echo $lines $ps | xargs -n1 | sort -u
done