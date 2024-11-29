# Check whether vowel or consonant

#!/bin/sh
echo "Enter a character:"
read ch
case $ch in
    "a" | "A") echo "Vowel";; 
    "e" | "E") echo "Vowel";; 
    "i" | "I") echo "Vowel";; 
    "o" | "O") echo "Vowel";; 
    "u" | "U") echo "Vowel";; 
    *) echo "Consonant";;
esac