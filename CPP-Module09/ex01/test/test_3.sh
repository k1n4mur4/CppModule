#!/bin/bash

ARGS=(
	"9 9 - 0 / 9 - 9 - 4 - 1 +"
	"7 7 - 8 /"
	"1 2 * 2 / 2 * 2 4 - + 1 /"
)
TARGET="./bin/RPN"

echo
echo "********** TEST 3 **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- $TARGET \"$arg\" -----"
	"$TARGET" "$arg"
	echo
done
