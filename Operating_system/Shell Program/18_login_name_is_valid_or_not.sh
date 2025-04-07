

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

# output

# sukdeb@sukdeb-OptiPlex-5050:~/Desktop/AB_sir$ bash 18_login_name_is_valid_or_not.sh 
# Enter login name: sukdeb
# 'sukdeb' is valid.
# sukdeb@sukdeb-OptiPlex-5050:~/Desktop/AB_sir$ bash 18_login_name_is_valid_or_not.sh 
# Enter login name: amit
# 'amit' is not valid.
