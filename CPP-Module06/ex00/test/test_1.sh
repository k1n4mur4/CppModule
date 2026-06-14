# !/bin/bash

ARGS=("0" "nan" "42.0f")
PROJECT_ROOT= "../"
TARGET="./bin/convert"

echo
echo "********** TEST 1 **********"
echo

for arg in "${ARGS[@]}"; do
	echo "----- ./convert $arg -----"
	"$TARGET" "$arg"
	echo
done
