# Write a shell script to find factorial of a number.

factorial()
{
    n=$1
    max=1
    
    while [ $n -ge 1 ]
    do
        max=`expr $max \* $n`
        n=`expr $n - 1`
    done
    echo "factorial of $m is $max"
}

read -p "Enter a number: " m
factorial $m 


# output
#Enter a number: 6
# factorial of 6 is 720
