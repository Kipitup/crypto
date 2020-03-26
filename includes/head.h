/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2020/03/26 18:55:12 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft.h"
// # include "auto_project.h"

typedef t_vector	*(*t_feistel_hash)(t_vector *);

typedef struct 		s_crypt{
	t_vector 		*msg;
	t_vector 		*key;
	t_feistel_hash	hash;
}					t_crypt

#endif
