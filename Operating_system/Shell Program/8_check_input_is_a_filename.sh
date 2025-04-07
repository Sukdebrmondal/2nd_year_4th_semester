# Write a shell script to check whether the input is a filename. If the file is black delete it and show proper message.


# read -p "Enter the file name : " file

# if [ -f "$file" ]
# then
# 	count=$(wc -c < $file)

# 	if [ $count -eq 0 ]
# 	then
# 		rm $file
# 		echo "Done removing file"
# 	else
# 		echo "Non-empty file"

# 	fi

# else
# 	echo "Not a file"
# fi

# 8. Write a shell script to check whether the input is a filename. If the file is black delete it and show proper message.


read -p "enter the file name: " f

if [ -f "$f" ]
then
    var=$(wc -c < $f)
    echo "number of characters in the file is " $var
    if [ $var -eq 0 ]
    then 
        rm -f $f
        echo "file has been delete"
    else
        echo "file can not be deleted"
    fi
else
    echo "file $f does not exist"

fi