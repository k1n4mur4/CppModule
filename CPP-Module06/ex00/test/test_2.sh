# !/bin/bash

ARGS=("1" "a" "!" "test")
PROJECT_ROOT= "../"
TARGET="./bin/convert"

echo
echo "********** TEST 2 **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- ./convert $arg -----"
	"$TARGET" "$arg"
	echo
done
