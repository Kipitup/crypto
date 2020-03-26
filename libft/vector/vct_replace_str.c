/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_replace_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:58:09 by amartino          #+#    #+#             */
/*   Updated: 2020/02/27 17:43:28 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Search the vector to find if a given 'str' string exist in the vector.
**	If it does, replace it with the given 'replace' string.
**
**	Return FAILURE if a malloc failed or the number of occurence.
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

ssize_t			replace_func(t_vector *vector, char *str, char *replace,
								size_t to_ignore)
{
	t_vector	*dup;
	ssize_t		index;
	ssize_t		state;
	size_t		len_str;
	size_t		len_replace;

	len_str = ft_strlen(str);
	len_replace = ft_strlen(replace);
	dup = vct_dup_from(vector, to_ignore);
	state = dup == NULL ? FAILURE : FALSE;
	if (state != FAILURE)
		index = vct_chr_str(dup, str);
	if (state != FAILURE && index >= 0)
	{
		index = index + to_ignore;
		state = vct_addstr_at(vector, replace, index);
		if (state == SUCCESS)
		{
			vct_pop_from(vector, len_str, (index + len_replace));
			state = replace_func(vector, str, replace, (index + len_replace));
			state = state == FAILURE ? FAILURE : (state + 1);
		}
	}
	vct_del(&dup);
	return (state);
}

ssize_t			vct_replace_str(t_vector *vector, char *str, char *replace)
{
	ssize_t		state;

	state = FAILURE;
	if (vector != NULL && vector->str != NULL && str != NULL && replace != NULL)
		state = replace_func(vector, str, replace, 0);
	return (state);
}
