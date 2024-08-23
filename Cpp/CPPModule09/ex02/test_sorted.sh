#!/bin/bash

MAX_VALUE=3000

PMERGEME_PATH="./PmergeMe"

for NUM_ELEMENTS in $(seq 1 $MAX_VALUE)
do
    RANDOM_INPUT=$(jot -r $NUM_ELEMENTS 1 100000 | tr '\n' ' ')
    
    OUTPUT=$($PMERGEME_PATH $RANDOM_INPUT)
    
    if echo "$OUTPUT" | grep -q "not sorted"; then
        echo "Test failed: The array was not sorted correctly."
        echo "Number of elements: $NUM_ELEMENTS"
        echo "Input: $RANDOM_INPUT"
        break
    else
        echo "Test passed: The array with $NUM_ELEMENTS elements was sorted correctly."
    fi
done

echo "All tests completed."

