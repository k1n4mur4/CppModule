# !/bin/bash

ARGS=("nan" "nanf" "+inf" "-inf" "+inff" "-inff" "nann" "nnan" "+infff" "-infff" "na" "in" "n" "i" "+" "-")
PROJECT_ROOT= "../"
TARGET="./bin/convert"

echo
echo "********** TEST 4 **********"
echo "          inf Test          "
echo

for arg in "${ARGS[@]}"; do
	echo "----- ./convert $arg -----"
	"$TARGET" "$arg"
	echo
done
