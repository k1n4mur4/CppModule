#!/bin/bash

ARGS=("input.txt")
PROJECT_ROOT="../"
TARGET="./bin/btc"

echo
echo "********** TEST 1 **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- $TARGET ./$arg -----"
	"$TARGET" ./test/$arg
	echo
done
