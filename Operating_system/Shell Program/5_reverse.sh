# Write a shell script to reverse a number without using ‘rev’. Take input as command line argument.
echo "enter the number: " $1
a=$1
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


# output
# sukdeb@sukdeb-OptiPlex-5050:~/Desktop/AB_sir$ bash 5_reverse.sh 564
# enter the number:  564
# reversed number is  465
