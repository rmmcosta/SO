#!/bin/bash
echo ------------- First for operator Demo -----------------
for i in 0 1 2
do    
    echo $i
done

echo ------------

for i in $(seq 0 10)
do
    echo $i
done

echo -------------

for f in $(ls /usr/include/*.h)
do  
    echo filename: $f
done