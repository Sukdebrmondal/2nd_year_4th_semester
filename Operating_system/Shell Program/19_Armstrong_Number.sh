

#!/bin/bash

read -p "Enter a number: " num
temp=$num
sum=0

# Count number of digits
n=${#num}

# Loop through digits
while [ $temp -gt 0 ]
do
    digit=$((temp % 10))
    power=$(echo "$digit ^ $n" | bc)
    sum=$((sum + power))
    temp=$((temp / 10))
done

# Check result
if [ $sum -eq $num ]; then
    echo "$num is an Armstrong number."
else
    echo "$num is NOT an Armstrong number."
fi
