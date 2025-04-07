



#!/bin/bash

# Read base and exponent
read -p "Enter the base: " base
read -p "Enter the exponent: " exp

# Calculate power using bc (bash doesn't support floating point natively)
result=$(echo "$base ^ $exp" | bc)

# Print result
echo "$base raised to the power $exp is: $result"
