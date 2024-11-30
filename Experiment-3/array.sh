# Print array items with indices

#!/bin/sh
Array=(A B C D)
echo "First element: ${Array[0]}"
for i in "${!Array[@]}"; do
    echo "Index: $i, Element: ${Array[$i]}"
done