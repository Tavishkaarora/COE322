#!/bin/bash

#check if there is an input
if [ -z "$1" ]; then
    echo "Error: No input provided"
    echo "Usage: $0 nnn"
    exit 1
fi

#heck if the input is -h
if [ "$1" == "-h" ]; then
    echo "Usage: $0 nnn"
    echo "nnn is a positive integer"
    exit 0
fi

#check if input is >0
if ! [[ "$1" =~ ^[0-9]+$ ]] || [ "$1" -le 0 ]; then
    echo "Error: Input must be a positive integer"
    echo "Usage: $0 nnn"
    exit 1
fi

#run fizzbuzz program
./fizzbuzz "$1"
