# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_protos.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 19:02:24 by ldevelle          #+#    #+#              #
#    Updated: 2020/02/29 18:26:48 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/bash

# Create a header file of every prototypes of function declared in $3$2$1

# usage:	./03 my_subfolder ../srcs/minishell/
			# Will create in ./includes/auto/auto_my_subfolder.h a header file
			# with prototypes of all functions in ../srcs/minishell/my_subfolder

# $1 (terminal) will be the name of directory of interest
		# It will also be used in naming the new header file

# $2 (../srcs/minishell/) will be the path (from where the .sh is executed)
		# It is the pass which goes to your folder of interest,
		# it will be used $2$1 so you may want to add a '/' at the end

# $3 is fully optional and act exactly the same way as $2.
		# Will be used $3$2$1

# $4 is Project name, fore recursive Makegenius compatibility

path=includes/auto/
prefix=auto_
yy=_
suffix=_H
extension=.h
name=$path$prefix$4$yy$1$extension
spe=$prefix$4$yy$1$suffix

mkdir -p $path
# rm -rf $name

if [ "$(uname)" == "Darwin" ]; then
	echo "#ifndef \c" > $name
	printf $spe | awk '{ print toupper($1) }' >> $name
	echo "# define \c" >> $name
	printf $spe | awk '{ print toupper($1) }' >> $name
	echo "" >> $name
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
	echo -n "#ifndef " > $name
	printf $spe | awk '{ print toupper($1) }' >> $name
	echo -n "# define " >> $name
	printf $spe | awk '{ print toupper($1) }' >> $name
	echo "" >> $name
fi

find $3$2$1 -type f -exec cat {} \+ |
grep -v "static" |
grep -A1 "^[^$(printf '\t')]" |
grep -e "(" -e ")" |
grep -v -e '{' -e '}' -e "/--" -e '#' -e ";" -e "^$" |
grep -v -e ":+:" -e "+:+" -e "\*\* " -e "\*\*\$" -e "^\*\*" -e "\$\$" -e "{" -e "}" -e "/\\*" -e "\\*/" -e "--" -e while -e else -e "\*\\\\" -e if -e ";" -e "#include " -e "=" -e "->" -e "//" |
tr -s '\t' '\t\t' >> $name


if [ "$(uname)" == "Darwin" ]; then
	sed -i '' "s~)$~);~g" $name
	sed -i '' "s~	~		~g" $name
	sed -i '' "s~t_vector	~t_vector~g" $name
	sed -i '' "s~intmax_t	~intmax_t~g" $name
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
	sed -i "s~)$~);~g" $name
	sed -i "s~	~		~g" $name
	sed -i "s~t_vector	~t_vector~g" $name
	sed -i "s~intmax_t	~intmax_t~g" $name
fi

echo "" >> $name
echo "#endif" >> $name

vim -c :Stdheader -c:wq $name

# echo "includes/auto_$1.h\t\tcreated
