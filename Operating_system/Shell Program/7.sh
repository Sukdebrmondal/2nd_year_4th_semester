# Write a shell script to check whether a given string is Palindrome.

read -p "Enter the text: " text
wc=$(echo -n $text | wc -c )
echo "Text is: " $text
echo "Word in this text is : "$wc
count_first=1
count_last=0
j=$wc
c=0
while [ $count_first -le $j ]
do
    var=`expr $wc - $count_last `
    var2=`expr $text |cut -c $var`

    var3=`expr $text | cut -c $count_first`
    if [ $var2 = $var3 ]
    then 
        ((c++))
    fi
    ((count_first++))
    ((count_last++))
done
if [ $c = $wc ]
then
    echo "This is Palindrome"
else
    echo "This is not a palindrome"
fi

output
Enter the text: madam
Text is:  madam
Word in this text is : 5
This is Palindrome
