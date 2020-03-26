/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:51:29 by ezalos            #+#    #+#             */
/*   Updated: 2020/03/26 18:53:55 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/head.h"

t_vector	*fesitel(t_crypt *to_crypt)
{

}

void		rot(t_vector *vct, int rot)
{
	int		i;

	i = -1;
	while (++i < vct->len)
		vct->str[i] = (vct->str[i] + rot) % 256;
}

int		init(t_crypt *crypto, char *msg, char *key)
{
	crypto->msg = vct_newstr(msg);
	crypto->key = vct_newstr(key);
	if (crypto->msg->len % 2 == 1)
		vct_addchar(crypto->msg, '\0');
}

int		main(int ac, char **av)
{
	t_crypt	crypto;

	if (ac > 2)
	{
		init(&crypto, av[1], av[2]);
	}
	return (0);
}
