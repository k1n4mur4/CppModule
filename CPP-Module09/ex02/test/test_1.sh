#!/bin/bash

TARGET="./bin/PmergeMe"

ARGS=(
	"3 5 9 7 4"
	"`shuf -i 1-100000 -n 3000 | tr "\n" " "`"
	"\"-1\" \"2\""
)

echo
echo "********** TEST 1 **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- $TARGET $arg -----"
	"$TARGET" $arg
	echo
done
