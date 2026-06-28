#!/bin/bash

ARGS=(
	"8 9 * 9 - 9 - 9 - 4 + +"
	"7 7 * 7 - -"
	"1 2 * 2 / 2 * 2 4 - + /"
)
TARGET="./bin/RPN"

echo
echo "********** TEST 2 **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- $TARGET \"$arg\" -----"
	"$TARGET" "$arg"
	echo
done
