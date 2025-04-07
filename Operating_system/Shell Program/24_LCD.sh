
#!/bin/bash

# Read two numbers from the user
read -p "Enter the first number: " a
read -p "Enter the second number: " b

# Function to calculate GCD using Euclidean Algorithm
gcd() {
    x=$1
    y=$2
    while [ $y -ne 0 ]
    do
        temp=$y
        y=$((x % y))
        x=$temp
    done
    echo $x
}

# Call gcd function
GCD=$(gcd $a $b)

# Calculate LCM using the formula: LCM = (a * b) / GCD
LCM=$(( (a * b) / GCD ))

# Print the result
echo "LCM of $a and $b is: $LCM"
