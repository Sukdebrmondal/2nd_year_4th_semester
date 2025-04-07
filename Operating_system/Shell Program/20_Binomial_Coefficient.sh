


#!/bin/bash

# Function to compute factorial
factorial() {
    n=$1
    fact=1
    while [ $n -gt 1 ]
    do
        fact=$((fact * n))
        n=$((n - 1))
    done
    echo $fact
}

# Read n and r
read -p "Enter value of n: " n
read -p "Enter value of r: " r

# Validate inputs
if [ $r -gt $n ]; then
    echo "Invalid input: r should be less than or equal to n."
    exit 1
fi

# Calculate factorials
fact_n=$(factorial $n)
fact_r=$(factorial $r)
diff=$((n - r))
fact_n_r=$(factorial $diff)

# Calculate binomial coefficient
bin_coeff=$((fact_n / (fact_r * fact_n_r)))

# Display result
echo "Binomial Coefficient C($n, $r) is: $bin_coeff"
