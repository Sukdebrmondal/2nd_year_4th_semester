


#!/bin/bash

# Read the number
read -p "Enter a number: " num

# 0 and 1 are not prime
if [ $num -le 1 ]; then
    echo "$num is not a prime number."
    exit 0
fi

# Check for factors
is_prime=1  # assume prime
for (( i=2; i*i<=num; i++ ))
do
    if (( num % i == 0 )); then
        is_prime=0
        break
    fi
done

# Output result
if [ $is_prime -eq 1 ]; then
    echo "$num is a prime number."
else
    echo "$num is not a prime number."
fi
