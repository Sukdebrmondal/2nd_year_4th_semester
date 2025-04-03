


#  18. Write a shell script to check whether an input login name is valid or not.


is_valid() {
    if id "$1" &>/dev/null
    then
        return 0
    else
        return 1
    fi
}

read -p "Enter login name: " name

if is_valid "$name"
then
    echo "'$name' is valid."
else
    echo "'$name' is not valid."
fi