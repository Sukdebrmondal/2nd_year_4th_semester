



#!/bin/bash

echo "----- Basic Calculator -----"

# Read two numbers
read -p "Enter the first number: " a
read -p "Enter the second number: " b

# Display menu
echo "Choose operation:"
echo "1. Addition (+)"
echo "2. Subtraction (-)"
echo "3. Multiplication (*)"
echo "4. Division (/)"
echo "5. Modulus (%)"

read -p "Enter your choice [1-5]: " choice

# Perform operation based on user choice
case $choice in
    1) result=$((a + b))
       echo "Result: $a + $b = $result"
       ;;
    2) result=$((a - b))
       echo "Result: $a - $b = $result"
       ;;
    3) result=$((a * b))
       echo "Result: $a * $b = $result"
       ;;
    4) if [ $b -eq 0 ]; then
           echo "Error: Division by zero!"
       else
           result=$(echo "scale=2; $a / $b" | bc)
           echo "Result: $a / $b = $result"
       fi
       ;;
    5) result=$((a % b))
       echo "Result: $a % $b = $result"
       ;;
    *) echo "Invalid choice. Please enter a number between 1 and 5."
       ;;
esac

