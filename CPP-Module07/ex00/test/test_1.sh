#!/bin/bash

ARGSX=("1" "0" "42" "tokyo")
ARGSY=("2" "0" "Paris" "school")
PROJECT_ROOT="../"
TARGET="./bin/swap"

echo
echo "********** TEST 1 **********"
echo

for argx in "${ARGSX[@]}"; do
	for argy in "${ARGSY[@]}"; do
		echo "----- ./swap $argx $argy -----"
		"$TARGET" "$argx" "$argy"
		echo
	done
done
