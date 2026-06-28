#!/bin/bash

ARGS=(
	"8 9 * 9 - 9 - 9 - 4 - 1 +"
	"7 7 * 7 -"
	"1 2 * 2 / 2 * 2 4 - +"
	"(1 + 1)"
)
TARGET="./bin/RPN"

echo
echo "********** TEST 1 **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- $TARGET \"$arg\" -----"
	"$TARGET" "$arg"
	echo
done
