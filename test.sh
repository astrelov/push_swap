#!/bin/bash

echo "PID of test = $$"
echo $$ > test_pid_file

NUMBERS=""
count=1
NBRSAMOUNT=500

count2=1
TESTSAMOUNT=10

printf "\n\ttesting $NBRSAMOUNT numbers $TESTSAMOUNT times\n\n"

while [ "$count2" -le $TESTSAMOUNT ]
do
    count=1
    NUMBERS=""
    let "count2 += 1"
    while [ "$count" -le $NBRSAMOUNT ]      # Generate ($MAXCOUNT) random integers.
    do
        NUMBERS+=$(od -N 3 -t uL -An /dev/random | tr -d " ")
        NUMBERS+=" "
        let "count += 1"
    done
#    echo $NUMBERS
    ./cmake-build-debug/push_swap $NUMBERS | wc -w # > ./output.txt && ./cmake-build-debug/checker $NUMBERS           # | wc -w
done

NUMBERS=""
count=1
NBRSAMOUNT=100

count2=1
TESTSAMOUNT=10

printf "\n\ttesting $NBRSAMOUNT numbers $TESTSAMOUNT times\n\n"

while [ "$count2" -le $TESTSAMOUNT ]
do
    count=1
    NUMBERS=""
    let "count2 += 1"
    while [ "$count" -le $NBRSAMOUNT ]      # Generate ($MAXCOUNT) random integers.
    do
        NUMBERS+=$(od -N 3 -t uL -An /dev/random | tr -d " ")
        NUMBERS+=" "
        let "count += 1"
    done
#    echo $NUMBERS
    ./cmake-build-debug/push_swap $NUMBERS | wc -w  # > ./output.txt &&  ./cmake-build-debug/checker $NUMBERS       # | wc -w
done




# endless loop for leaks testing
while :
do
    i=1
done
