# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init_makegenius.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezalos <ezalos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/08 19:55:41 by ezalos            #+#    #+#              #
#    Updated: 2020/03/08 21:16:45 by ezalos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/bash

init_path="init.mk"
user_input=""

if [ "$(expr substr $(uname -s) 1 5)" = "Linux" ]
then
	RED="\e[31m"
	GREEN="\e[32m"
	YELLOW="\e[33m"
	BLUE="\e[34m"
	MAGENTA="\e[35m"
	CYAN="\e[36m"
	END="\e[0m"
elif [ "$(uname)" = "Darwin" ]
then
	RED="\x1b[31m"
	GREEN="\x1b[32m"
	YELLOW="\x1b[33m"
	BLUE="\x1b[34m"
	MAGENTA="\x1b[35m"
	CYAN="\x1b[36m"
	END="\x1b[0m"
fi


ask_user()
{
	echo -n $RED
	echo "$1"
	echo -n $CYAN
	echo "	Here's a grep of the default value as well as the comment."
	echo "	Press enter to keep default value"
	echo -n $END
	show_context "$2" "$3"

	echo -n $YELLOW
	read ans
	echo -n $END
	user_input=$ans
}

fill_init()
{
	search_for="$2$1"
	replace_with="$2$user_input"
	if [ -z "$user_input" ]
	then
		echo -n $YELLOW
		echo "Default value has been kept !"
		echo -n $END
	else
		if [ "$(uname)" = "Darwin" ]
		then
			sed -i '' "s~$search_for~$replace_with~g" $init_path
		elif [ "$(expr substr $(uname -s) 1 5)" = "Linux" ]
		then
			sed -i "s~$search_for~$replace_with~g" $init_path
		fi
	fi
}

show_context()
{
	what_to_grep="$2$1"
	grep -B1  "$what_to_grep" $init_path
}

ask_and_fill()
{
	ask_user "$1" "$2" "$3"
	fill_init "$2" "$3"
	echo
	echo
}

ask_and_fill "What's your project name ?" "project_name" "NAME 					=	"
ask_and_fill "Is this project a Library ?" "n" "LIB_PRJCT 				=	"
ask_and_fill "What's your login for auteur file ?" "ldevelle" "login 					=	"
ask_and_fill "What's your github username ?" "ezalos" "github_username			=	"
ask_and_fill "What's your github project name ?" "\$(NAME)" "github_project			=	"

echo
echo
echo -n $RED
echo "Setup is complete."
echo "Do not hesitate to look and adjust all the available options in init.mk !"
echo "Thank you for using Makegenius !"
echo -n $END
echo
echo
