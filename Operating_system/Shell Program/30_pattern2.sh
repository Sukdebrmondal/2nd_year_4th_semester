
#!/bin/bash

# Read number of rows
read -p "Enter number of rows: " n

for (( i=n; i>=1; i-- ))
do
    for (( j=1; j<=i; j++ ))
    do
        echo -n "* "
    done
    echo
done
