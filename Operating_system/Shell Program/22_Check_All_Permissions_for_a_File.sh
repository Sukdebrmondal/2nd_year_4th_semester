

#!/bin/bash

# Read file name from user
read -p "Enter the file name: " file

# Check if file exists
if [ ! -e "$file" ]; then
    echo "File does not exist."
    exit 1
fi

# Check read, write, execute permissions for the user
if [ -r "$file" ] && [ -w "$file" ] && [ -x "$file" ]; then
    echo "The file '$file' has all permissions (read, write, execute) for the user."
else
    echo "The file '$file' does NOT have all permissions for the user."
    echo -n "Missing permissions: "
    [ ! -r "$file" ] && echo -n "read "
    [ ! -w "$file" ] && echo -n "write "
    [ ! -x "$file" ] && echo -n "execute"
    echo
fi
