# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_makegenius.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 17:26:31 by ldevelle          #+#    #+#              #
#    Updated: 2020/03/08 14:10:17 by ezalos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/bash

# Update Makegenius depedencies
temp_folder=$1
rm_old_files="./.makegenius/scripts/what_to_del_for_update.sh"
source $rm_old_files
for i in "${files_to_delete[@]}"
do
	rm -rf $i
done

update_sources="./.makegenius/scripts/what_to_get_for_update.sh"
source $temp_folder$update_sources
for i in "${files_to_copy[@]}"
do
	cp -rf $temp_folder$i .
done

make rm_update_tmp_dir &

#if [ "$(uname)" == "Darwin" ]; then
#elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
#fi
