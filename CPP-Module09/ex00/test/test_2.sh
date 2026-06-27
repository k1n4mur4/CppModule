#!/bin/bash

ARGS=("test_input_1.txt" "test_input_2.txt" "test_input_3.txt" "test_input_4.txt" "test_input_5.txt" "test_input_empty.txt")
PROJECT_ROOT="../"
TARGET="./bin/btc"

echo
echo "********** TEST 2 **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- $TARGET ./$arg -----"
	"$TARGET" ./test/$arg
	echo
done
