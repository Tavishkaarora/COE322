#!/bin/bash

#check if there is an input
if [ -z "$1" ]; then
    echo "Error: Number was not entered"
    exit 1
fi

#heck if the input is -h
if [ "$1" == "-h" ]; then
    echo "Usage: $0 nnn"
    echo "nnn is a positive integer"
    exit 0
fi

#check if input is >0
if ! [[ "$1" =~ ^[1-9][0-9]*$ ]]; then
    echo "Error: You must enter a positive integer"
    echo "Usage: $0 nnn"
    exit 1
fi


#run fizzbuzz program
./fizzbuzz "$1"
