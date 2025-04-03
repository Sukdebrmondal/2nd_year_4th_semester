# Write a shell script to print odd numbers in a range.

read -p "Enter the starting number: " p
read -p "Enter the ending number: " b
((b++))
a=$p
echo "even numbers are: "
while [ $a -ne $b ]
do
    res=`expr $a % 2`
    if [ $res -eq 0 ]
    then
        echo $a
    fi
    ((a++))
done
a=$p
echo "odd numbers are: "
while [ $a -ne $b ]
do
    res=`expr $a % 2`
    if [ $res -ne 0 ]
    then
        echo $a
    fi
    ((a++))
done


output
Enter the starting number: 1
Enter the ending number: 10
even numbers are: 
2
4
6
8
10
odd numbers are: 
1
3
5
7
9
