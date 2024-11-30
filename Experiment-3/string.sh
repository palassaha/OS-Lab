# String copy using function

#!/bin/bash
copy_string() {
    local src="$1"
    local -n dest="$2"
    dest="$src"
}

src_str="hello world"
copy_string "$src_str" copied_str

echo "Source String: $src_str"
echo "Copied String: $copied_str"
