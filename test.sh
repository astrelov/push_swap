#!/bin/bash

NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'

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
    ./cmake-build-debug/push_swap $NUMBERS > ./output.txt &&  ./cmake-build-debug/checker $NUMBERS

     WORDS=$(cat output.txt | wc -w)

    if [ "$WORDS" -gt 5500 ]; then
        echo -e "${RED}${WORDS}${NC}"
    else
        echo -e "${GREEN}${WORDS}${NC}"
    fi
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
    ./cmake-build-debug/push_swap $NUMBERS > ./output.txt &&  ./cmake-build-debug/checker $NUMBERS

     WORDS=$(cat output.txt | wc -w)

    if [ "$WORDS" -gt 700 ]; then
        echo -e "${RED}${WORDS}${NC}"
    else
        echo -e "${GREEN}${WORDS}${NC}"
    fi
done




# endless loop for leaks testing
while :
do
    i=1
done
