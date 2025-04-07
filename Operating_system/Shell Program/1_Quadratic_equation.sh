# Write a shell script to show roots of a quadratic equation

read -p "enter 1st number : " a
read -p "enter 2nd number : " b
read -p "Enter 3rd number : " c
de=`echo "scale=5;(($b ^ 2) - (4 * $a * $c))" |bc`
# echo $de
res1=`echo "scale=5;((-($b) + sqrt($de))/ (2 * $a))" |bc`
res2=`echo "scale=5;((-($b) - sqrt($de)) / ( 2 * $a))" |bc`
echo 'X1 : ' $res1
echo 'X2 : ' $res2

# output ->
# enter 1st number : 1
# enter 2nd number : -5
# Enter 3rd number : 6
# X1 :  3.00000
# X2 :  2.00000
