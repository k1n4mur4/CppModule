# !/bin/bash

ARGS=("0" "1" "2" "3" "4" "5" "6" "7" "8" "9" "-1" "2147483647" "2147483648" "-2147483648" "-2147483649")
PROJECT_ROOT= "../"
TARGET="./bin/convert"

echo
echo "********** TEST 5 **********"
echo "          INT Test         "
echo

for arg in "${ARGS[@]}"; do
	echo "----- ./convert $arg -----"
	"$TARGET" "$arg"
	echo
done
