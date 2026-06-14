# !/bin/bash

ARGS=("42.0f" "0.1f" "-0.1f" "-42.0f" "-42.0ff" "f" ".0f" ".9f" ".9.9f")
PROJECT_ROOT= "../"
TARGET="./bin/convert"

echo
echo "********** TEST 6 **********"
echo "         Float Test         "
echo

for arg in "${ARGS[@]}"; do
	echo "----- ./convert $arg -----"
	"$TARGET" "$arg"
	echo
done
