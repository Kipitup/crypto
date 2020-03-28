/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2020/03/28 17:32:28 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft.h"
// # include "auto_project.h"

# define FEISTEL_CYCLES		1

typedef void	(*t_feistel_hash)(t_vector *, t_vector *);

typedef struct 		s_crypt{
	t_vector 		*msg;
	t_vector 		*key;
	t_feistel_hash	hash;
	size_t			nb_cycles;
}					t_crypt;

void	clean_feistel(t_crypt **crypto);
#endif
