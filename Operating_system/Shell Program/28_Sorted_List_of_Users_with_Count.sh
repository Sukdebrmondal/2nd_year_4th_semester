

#!/bin/bash

echo "Logged-in users (sorted):"
# Get list of users, sort and remove duplicates
users=$(who | awk '{print $1}' | sort | uniq)

# Display sorted unique users
echo "$users"

# Count the total number of unique users
count=$(echo "$users" | wc -l)
echo "Total number of unique users logged in: $count"
