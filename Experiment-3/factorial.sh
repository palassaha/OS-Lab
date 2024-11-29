# WAP to print factorial of a number using for and while loop

#!/bin/sh
echo "Enter a number: "
read n

# Factorial using for loop
fact=1
for ((i=1; i<=n; i++)); do
    fact=$((fact * i))
done
echo "Factorial using for loop is $fact"

# Factorial using while loop
fact=1
num=$n
while [ $num -gt 1 ]; do
    fact=$((fact * num))
    num=$((num - 1))
done
echo "Factorial using while loop is $fact"
