




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
fact_n_r=$(factorial $((n - r)))

# Calculate permutation
permutation=$((fact_n / fact_n_r))

# Display result
echo "Permutation P($n, $r) is: $permutation"
