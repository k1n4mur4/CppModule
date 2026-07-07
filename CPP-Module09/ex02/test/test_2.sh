#!/bin/bash

TARGET="./bin/PmergeMe"

ARGS=(
	"3 5 9 7 4"
	"`shuf -i 1-10 -n 10 | tr "\n" " "`"
	"\"-1\" \"2\""
)

echo
echo "********** SHORT TEST **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- $TARGET $arg -----"
	"$TARGET" $arg
	echo
done
