# Write a shell script to perform sorting.

read -p "Enter the number of elements:" a
i=0
while [ $i -lt $a ]
do
    read arr[$i]
    ((i++))
done
echo "The unsorted array was " ${arr[*]}

i=0
while [ $i -lt $a ]
do  
    j=0
    ((a--))
    while [ $j -lt $a ]
    do
        jp=`expr $j + 1`
        if [ ${arr[$j]} -lt ${arr[$jp]} ]
        then
            temp=${arr[$j]}
            arr[$j]=${arr[$jp]}
            arr[$jp]=$temp
        fi
        ((j++))
    done
    ((i++))
done

echo "the Descending order sorted array is " ${arr[*]}

# output
# Enter the number of elements:5
# 3 
# 45 
# 6
# 12
# 6
# The unsorted array was  3 45 6 12 6
# the Descending order sorted array is  45 12 6 6 3

