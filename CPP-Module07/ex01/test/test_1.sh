#!/bin/bash

ARGS=(
	"hello"
	"hello world"
	"This is 42 tokyo"
	"C C++ Python Go Rust"
	"HTML CSS JavaScript TypeScript"
)
cd "$(dirname "$0")/.." || exit 1
TARGET="./bin/iter"

echo
echo "********** TEST 1 **********"
echo

for args in "${ARGS[@]}"; do
	echo "----- ./iter $args -----"
	"$TARGET" $args
	echo
done
