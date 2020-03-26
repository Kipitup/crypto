/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:43:23 by amartino          #+#    #+#             */
/*   Updated: 2020/02/26 17:58:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Apply the function that you give as parameter to the vector.
**	vct_apply was designed to be as modular as possible. You will find a enum in
**	vector.h, with all the possible function you can use. If you need to use a
**	different type of prototype, just the function pointer you need as below
*/

t_char_ptr_func		apply_func(enum e_apply type)
{
	static	t_char_ptr_func	func[] = {	ft_strupcase, ft_strlowcase,
										ft_strcapitalize
									};

	return (func[type]);
}

t_int_func			test_func(enum e_apply type)
{
	static	t_int_func	func[] = {ft_strisupcase, ft_strislowcase,
								ft_strisblank
								};

	return (func[type]);
}

int					vct_apply(t_vector *vector, enum e_apply type)
{
	int		ret;

	ret = 0;
	if (vector != NULL && vector->str != NULL)
	{
		if (type < NB_OF_APPLY_FUNC)
			apply_func(type)(vector->str);
		else if (type < NB_TOTAL_OF_FUNC)
			ret = test_func(type - NB_OF_APPLY_FUNC)(vector->str);
	}
	return (ret);
}
