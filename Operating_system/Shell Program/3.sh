# Write a shell script to print sum of digits of a number.

read -p "enter the number: " a

sum=0
r=10
while [ $a -ne 0 ]
do
    res=`expr $a % $r`
    sum=`expr $sum + $res`
    a=`expr $a - $res`
    a=`expr $a / $r`
done

echo "The Sum of the Digit is : "$sum


output
enter the number: 123
The Sum of the Digit is : 6