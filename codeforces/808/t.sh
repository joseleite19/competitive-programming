# !/bin/bash

# filename=attempts.json
# newfile=gg
# PAT="    \"_id\":"
OFF=18519
# while IFS= read line
# do
# 	if echo "$line" | grep -q "$PAT"; then
# 		sum=$(sed 's/[    \"_id\",:]//g' <<< "$line")
# 		sum=$(($sum + $OFF))
# 	    echo "$PAT $sum," &>> "$newfile"
# 	else
# 	    echo "$line" &>> "$newfile"
# 	fi
# done < "$filename"
limit=2236

for pasta in */; do
	id=$(sed 's/[\/]//g' <<< "$pasta")
	if [ "$id" -lt "$limit" ]; then
		newid=$(($id + $OFF));
		mv "$id" "$newid";
	fi
done


# addr=oi
# port=er
# username=asd
# sed -i 's/address=.*/address='$addr'/' $filename
# sed -i 's/port=.*/port='$port'/' $filename
# sed -i 's/username=.*/username='$username'/' $filename