#!/usr/bin/env bash

while true
do
    PID="$(head -1 "./test_pid_file")"
    clear
    leaks $PID
    sleep 2
done
