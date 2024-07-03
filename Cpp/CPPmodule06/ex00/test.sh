#!/bin/bash

# Define the test cases
test_cases=(
    "0"
    "-42"
    "42"
    "a"
    "0.0f"
    "-4.2f"
    "4.2f"
    "-inff"
    "+inff"
    "nanf"
    "0.0"
    "-4.2"
    "4.2"
    "-inf"
    "+inf"
    "nan"
    ""                # Empty string
    " "               # Space
    "2147483647"      # INT_MAX
    "-2147483648"     # INT_MIN
    "2147483648"      # INT_MAX + 1
    "-2147483649"     # INT_MIN - 1
    "127"             # CHAR_MAX
    "-128"            # CHAR_MIN
    "128"             # CHAR_MAX + 1
    "-129"            # CHAR_MIN - 1
    "3.40282346638528e+38f"   # FLT_MAX
	"1.17549e-38f"	  # FLT_MIN
	"1.17549435e-38f"
    "3.40282346638528e+38"   # FLT_MAX as doubl
    "1.17549e-38"  # FLT_MIN as double
    "1e309"           # Overflow double
    "-1e309"          # Underflow double
    "42.1234567890123456789" # High precision double
	"0.000000001e-37"
)

# Run each test case
for case in "${test_cases[@]}"; do
    echo "Test case: '$case'"
    ./convert "$case"
    echo "-------------------------"
done

