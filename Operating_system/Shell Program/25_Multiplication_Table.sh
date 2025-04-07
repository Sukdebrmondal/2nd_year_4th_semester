

#!/bin/bash

# Read the number
read -p "Enter a number: " num

# Print table from 1 to 10
echo "Multiplication Table of $num:"
for i in {1..10}
do
    echo "$num x $i = $((num * i))"
done
