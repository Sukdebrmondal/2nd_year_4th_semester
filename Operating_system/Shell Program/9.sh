# Write a shell script to find the largest number in an array.

read -p "Enter the number of elements in the array: " a
echo "Enter the elements of the array:"
i=0
while [ $i -lt $a ]
do 
    read arr[$i]
    ((i++))
done
echo ${arr[*]}

i=0
max=${arr[0]}
min=${arr[0]}
while [ $i -lt $a ]
do
    if [ $max -lt ${arr[$i]} ] 
    then
        max=${arr[$i]}
    fi
    if [ $min -gt ${arr[$i]} ] 
    then
        min=${arr[$i]}
    fi
    ((i++))
done
echo "maximum number of this array is "$max " and minimum number of this array is "$min



output
Enter the number of elements in the array: 5
Enter the elements of the array:
32
3
2
56
7
32 3 2 56 7
maximum number of this array is 56  and minimum number of this array is 2
