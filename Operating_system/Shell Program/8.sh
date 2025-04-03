# Write a shell script to check whether the input is a filename. If the file is black delete it and show proper message.

read -p "enter the file name: " f
var=$(wc -c < $f)
echo "number of characters in the file is " $var
if [ $var -eq 0 ]
then rm -f $f
echo "file has been delete"
else
echo "file can not be deleted"
fi

output
enter the file name: 1.sh
number of characters in the file is  479
file can not be deleted

