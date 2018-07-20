#!/bin/bash

#make re

checker="./checker"
push_swap="./push_swap"

TESTSAMOUNT_500=10
TESTSAMOUNT_100=10
TESTSAMOUNT_5=0
TESTSAMOUNT_3=0

NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'

if [[ "$TESTSAMOUNT_500" > 0 ]]; then

    NUMBERS=""
    count=1
    NBRSAMOUNT=500
    count2=1
    SUCCESSFUL=0
    SUM=0

    printf "\n\t${ORANGE}testing $NBRSAMOUNT numbers $TESTSAMOUNT_500 times${NC}\n\n"

    while [ "$count2" -le $TESTSAMOUNT_500 ]
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
        $push_swap $NUMBERS > ./output.txt &&  $checker $NUMBERS < output.txt

         WORDS=$(cat output.txt | wc -w)
         let "SUM += $WORDS"

        if [ "$WORDS" -gt 5500 ]; then
            echo -e "${RED}${WORDS}${NC}"
        else
            echo -e "${GREEN}${WORDS}${NC}"
            let "SUCCESSFUL += 1"
        fi
    done

    echo "SUCCESSFUL ATTEMPTS: $SUCCESSFUL"
    let "SUM = SUM / TESTSAMOUNT_500"
    if [ "$SUM" -gt 5500 ]; then
        echo -e "AVERAGE OPERATIONS: ${RED}$SUM${NC}"
    else
        echo -e "AVERAGE OPERATIONS: ${GREEN}$SUM${NC}"
    fi
fi

if [[ "$TESTSAMOUNT_100" > 0 ]]; then

    NUMBERS=""
    count=1
    count2=1
    NBRSAMOUNT=100
    SUCCESSFUL=0
    SUM=0

    printf "\n\t${ORANGE}testing $NBRSAMOUNT numbers $TESTSAMOUNT_100 times${NC}\n\n"

    while [ "$count2" -le $TESTSAMOUNT_100 ]
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
#        echo $NUMBERS > NUMBERS
#        echo $NUMBERS
        $push_swap $NUMBERS > ./output.txt &&  $checker $NUMBERS < output.txt

         WORDS=$(cat output.txt | wc -w)
         let "SUM += $WORDS"

        if [ "$WORDS" -gt 700 ]; then
            echo -e "${RED}${WORDS}${NC}"
        else
            echo -e "${GREEN}${WORDS}${NC}"
            let "SUCCESSFUL += 1"
        fi
    done

    echo "SUCCESSFUL ATTEMPTS: $SUCCESSFUL"
    let "SUM = SUM / TESTSAMOUNT_100"
    if [ "$SUM" -gt 700 ]; then
        echo -e "AVERAGE OPERATIONS: ${RED}$SUM${NC}"
    else
        echo -e "AVERAGE OPERATIONS: ${GREEN}$SUM${NC}"
    fi
fi

if [[ "$TESTSAMOUNT_5" > 0 ]]; then

    NUMBERS=""
    count=1
    count2=1
    NBRSAMOUNT=5
    SUCCESSFUL=0
    SUM=0

    printf "\n\t${ORANGE}testing $NBRSAMOUNT numbers $TESTSAMOUNT_5 times${NC}\n\n"

    while [ "$count2" -le $TESTSAMOUNT_5 ]
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
#        echo $NUMBERS
        $push_swap $NUMBERS > ./output.txt &&  $checker $NUMBERS < output.txt

         WORDS=$(cat output.txt | wc -w)
         let "SUM += $WORDS"

        if [ "$WORDS" -gt 12 ]; then
            echo -e "${RED}${WORDS}${NC}"
        else
            echo -e "${GREEN}${WORDS}${NC}"
            let "SUCCESSFUL += 1"
        fi
    done

    echo "SUCCESSFUL ATTEMPTS: $SUCCESSFUL"
    let "SUM = SUM / TESTSAMOUNT_5"
    if [ "$SUM" -gt 12 ]; then
        echo -e "AVERAGE OPERATIONS: ${RED}$SUM${NC}"
    else
        echo -e "AVERAGE OPERATIONS: ${GREEN}$SUM${NC}"
    fi
fi


if [[ "$TESTSAMOUNT_3" > 0 ]]; then

    NUMBERS=""
    count=1
    count2=1
    NBRSAMOUNT=3
    SUCCESSFUL=0
    SUM=0

    printf "\n\t${ORANGE}testing $NBRSAMOUNT numbers $TESTSAMOUNT_3 times${NC}\n\n"

    while [ "$count2" -le $TESTSAMOUNT_3 ]
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
        $push_swap $NUMBERS > ./output.txt &&  $checker $NUMBERS < output.txt

         WORDS=$(cat output.txt | wc -w)
         let "SUM += $WORDS"

        if [ "$WORDS" -gt 2 ]; then
            echo -e "${RED}${WORDS}${NC}"
        else
            echo -e "${GREEN}${WORDS}${NC}"
            let "SUCCESSFUL += 1"
        fi
    done

    echo "SUCCESSFUL ATTEMPTS: $SUCCESSFUL"
    let "SUM = SUM / TESTSAMOUNT_3"
    if [ "$SUM" -gt 2 ]; then
        echo -e "AVERAGE OPERATIONS: ${RED}$SUM${NC}"
    else
        echo -e "AVERAGE OPERATIONS: ${GREEN}$SUM${NC}"
    fi
fi
