# Write a shell script to implement Stack.

arr=()
count=0

push(){
    arr[$2]=$1
    ind=0
    while [ $ind -le $count ]
    do
        echo ${arr[$ind]}
        ((ind++))
    done  
    ((count++))
}

pop(){
    ((count--))
    if [ $count -lt 0 ]
    then
        echo "underflow"
        ((count++))
    else
        ind=0
        while [ $ind -lt $count ]
        do
            echo ${arr[$ind]}
            ((ind++))
        done 
    fi
}


while true
do
    read -p "1) push 2) pop 3) exit: " m
    case $m in
        1) read -p "enter the number to push in the stack: " a
        push $a $count ;;
        2) pop ;;
        3) exit ;;
        *) echo "wrong" ;;
    esac
done


# output
# 1) push 2) pop 3) exit: 1
# enter the number to push in the stack: 43
# 43
# 1) push 2) pop 3) exit: 1
# enter the number to push in the stack: 34
# 43
# 34
# 1) push 2) pop 3) exit: 2
# 43
# 1) push 2) pop 3) exit: 3
