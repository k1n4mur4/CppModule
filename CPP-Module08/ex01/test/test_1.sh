#!/bin/bash

FIND=("42")
ARGS=("40 41 42 43 44 45" "0" "42 42 42" "0 42 tokyo")
PROJECT_ROOT="../"
TARGET="./bin/span"

echo
echo "********** TEST 1 **********"
echo

for find in "${FIND[@]}"; do
	for args in "${ARGS[@]}"; do
		echo "----- ./easyfind $find $args -----"
		"$TARGET" "$find" $args
		echo
	done
done
