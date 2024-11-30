# Check whether palindrome or not

#!/bin/bash
str="$1"

str=$(echo "$str" | tr -d "[:punct:][:space:]" | tr '[:upper:]' '[:lower:]')

rev_str=$(echo "$str" | rev)

if [ "$str" = "$rev_str" ]; then
    echo "Palindrome"
else
    echo "Not Palindrome"