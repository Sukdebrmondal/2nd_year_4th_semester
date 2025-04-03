# Write a shell script to reverse a number without using ‘rev’. Take input as command line argument.

read -p "Enter the number: " a

sum=0
r=10
while [ $a -ne 0 ]
do
    sum=`expr $sum \* $r`
    res=`expr $a % $r`
    sum=`expr $sum + $res`
    a=`expr $a - $res`
    a=`expr $a / $r`
    
done

echo "reversed number is " $sum


output
Enter the number: 123
reversed number is  321
