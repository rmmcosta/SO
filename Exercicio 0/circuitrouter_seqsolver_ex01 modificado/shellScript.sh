#!/bin/bash
for input in inputs/*txt
do
    echo ===== ${input} =====
    ./CircuitRouter-SeqSolver -p <"$input"
done