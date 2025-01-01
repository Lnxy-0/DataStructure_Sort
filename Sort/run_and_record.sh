#!/bin/bash

RUN_TIMES=6

RESULT_FILE="result.txt"

> $RESULT_FILE

for((i=1; i<=RUN_TIMES; i++)); do
    echo "Running main $i times..."
    echo "Experiment $i" >> $RESULT_FILE
    ./main | tail -n 3 >> $RESULT_FILE
    echo "" >> $RESULT_FILE
    sleep 1
done

echo "All runs completed. Results are saved in $RESULT_FILE"
