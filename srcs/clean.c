/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <a.martino@sutdent.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:07:49 by amartinod         #+#    #+#             */
/*   Updated: 2020/03/26 19:27:31 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	clean_feistel(t_crypt **crypto)
{
	if (crypto != NULL && *crypto != NULL)
	{
		vct_del(&((*crypto)->msg));
		vct_del(&((*crypto)->key));
		ft_memdel((void**)crypto);
	}
}

/*
vct_func(crypto, func_to_apply);

vct_func()
{
	crypto->str = func_to_apply(crypto->str, crypto->len);
}
*/
