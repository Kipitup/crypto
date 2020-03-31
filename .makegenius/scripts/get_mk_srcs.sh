# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_mk_srcs.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 19:03:06 by ldevelle          #+#    #+#              #
#    Updated: 2020/03/29 15:06:47 by ezalos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#! /bin/bash

# Create a .mk file with every .c listed inside $2$1

# usage:	sh get_mk_srcs terminal ../srcs/minishell/
# $1 (terminal) will be the name of directory of interest
# $2 (../srcs/minishell/) will be the path (from where the .sh is executed)
# $2 is fully optional

path=.makegenius/
prefx=srcs_path/pat_
extension=.mk
name=$path$prefx$1$extension

rm -rf $name
touch $name

# Creation .mk with full path to the file
find $3$2$1 -type f -exec ls -lrtA -d -1 {} \+ | sed "s~//~/~g" | grep -Eo "$2.+\.c" >> $name

if [ "$(uname)" == "Darwin" ]; then
	sed -i '' 's/$/ \\/' $name
	sed -i '' 's/^/	/' $name
	sed -i '' "1s/^/PAT += /" $name
	sed -i '' '1h;1!H;$!d;g;s/\(.*\)\\/\1/' $name
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
	sed -i 's/$/ \\/' $name
	sed -i 's/^/	/' $name
	sed -i "1s/^/PAT += /" $name
	sed -i '1h;1!H;$!d;g;s/\(.*\)\\/\1/' $name
fi

# echo "$1\t\tconverted to Makefile source"
