#!/bin/sh

echo "\033[1;31mWARNING : Handle this function carefully.
\t  \033[4mTHERE IS NO GOING BACK\033[0m\n"

read -p $'\033[1;33mWhat pattern would you like to replace ?\033[0m\n' var1

read -p $'\n\033[1;33mBy what should we replace it ?\n\033[0m' var2

echo "\n\033[1;33mHere are all the files that match your pattern:\033[0m"

for f in $(grep -r "$var1" . | cut -d ":" -f1 | egrep  "(\.h)|(\.c)")
	do echo "\033[1;37m$f\033[0m"
done 

read -p $'\nReplace ?  \033[1;32myes\033[0m  |  \033[1;31mno\033[0m\n' var3

echo "\n-----------------------------------------------\n"

if [ $var3 = "yes" ] || \
	[ $var3 = "y" ]
then
	for f in $(grep -r "$var1" . | cut -d ":" -f1 | egrep  "(\.h)|(\.c)")
		do sed -i '' "s~$var1~$var2~g" $f
	done
	grep -r "$var2" . | egrep "(\.h)|(\.c)"
else
	echo "Action cancelled"
fi
