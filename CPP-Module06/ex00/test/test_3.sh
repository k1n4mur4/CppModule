# !/bin/bash

ARGS=("a" "" "aa" "test" "\\")
PROJECT_ROOT= "../"
TARGET="./bin/convert"

echo
echo "********** TEST 3 **********"
echo "          Char Test         "
echo

for arg in "${ARGS[@]}"; do
	echo "----- ./convert $arg -----"
	"$TARGET" "$arg"
	echo
done
