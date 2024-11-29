# WAP to find the max among three numbers

#!/bin/sh
echo "Enter 1st no:"
read a
echo "Enter 2nd no:"
read b
echo "Enter 3rd no:"
read c

if [ "$a" -gt "$b" ] && [ "$a" -gt "$c" ]; then
    echo "$a is the greatest number"
elif [ "$b" -gt "$a" ] && [ "$b" -gt "$c" ]; then
    echo "$b is the greatest number"
else
    echo "$c is the greatest number"
fi