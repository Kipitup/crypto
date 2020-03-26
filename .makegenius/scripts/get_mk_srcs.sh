# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_mk_srcs.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 19:03:06 by ldevelle          #+#    #+#              #
#    Updated: 2020/03/08 14:05:03 by ezalos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#! /bin/bash

# Create a .mk file with every .c listed inside $2$1

# usage:	sh get_mk_srcs terminal ../srcs/minishell/
# $1 (terminal) will be the name of directory of interest
# $2 (../srcs/minishell/) will be the path (from where the .sh is executed)
# $2 is fully optional

path=.makegenius/mk_dependencies/
prefx=PAT/pat_
extension=.mk
name=$path$prefx$1$extension

rm -rf $name
touch $name

# Creation .mk with full path to the file
find $3$2$1 $4 -type f -exec ls -lrt -d -1 {} \+ | sed "s~//~/~g" | grep '\.c' >> $name

sed -i '' 's/$/ \\/' $name
sed -i '' 's/^/	/' $name
sed -i '' "1s/^/PAT += /" $name
sed -i '' '1h;1!H;$!d;g;s/\(.*\)\\/\1/' $name

# echo "$1\t\tconverted to Makefile source"
