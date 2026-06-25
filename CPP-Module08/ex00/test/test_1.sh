#!/bin/bash

FIND=("42")
ARGS=("40 41 42 43 44 45" "0" "42 43 42 42 43" "0 42 tokyo")
PROJECT_ROOT="../"
TARGET="./bin/easyfind"

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
