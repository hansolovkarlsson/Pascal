filename=$1
bin/pascal -c "$filename.pas" "$filename.bin"
bin/pascal -r "$filename.bin"

