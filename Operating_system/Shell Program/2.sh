
# Write a shell script to print largest number among three numbers.
echo "Enter three numbers: "
read -p "1st number: " a
read -p "2nd number: " b
read -p "3rd number: " c

if [ $a -gt $b ] && [ $a -gt $c ]
then
    echo "The largest number $a"
elif [ $b -gt $a ] && [ $b -gt $c ]
then
    echo "The largest number $b"
elif [ $c -gt $a ] && [ $c -gt $b ]
then
    echo "The largest number $c"
else
    echo "The largest number $a"
fi


output
Enter three numbers: 
1st number: -3
2nd number: 4
3rd number: 7
The largest number 7
