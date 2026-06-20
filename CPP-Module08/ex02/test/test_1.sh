#!/bin/bash

TARGET="./bin/stack"

# Each entry is one invocation's arguments.
# ""            -> no args: runs the subject demo
# "<numbers...>" -> option mode: pushes the numbers onto a MutantStack
# a non-numeric token triggers the usage message
ARGS=(
	""
	"5 17 3 5 737 0"
	"42"
	"-3 42 +7 0"
	"1 2 foo"
)

echo
echo "********** TEST 1 **********"
echo

for args in "${ARGS[@]}"; do
	echo "----- $TARGET $args -----"
	"$TARGET" $args
	echo
done
