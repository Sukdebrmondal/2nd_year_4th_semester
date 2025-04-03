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

echo "the sorted array is " ${arr[*]}

output
Enter the number of elements:5
54
3
6
83
5
The unsorted array was  54 3 6 83 5
the sorted array is  83 54 6 5 3
