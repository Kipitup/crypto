/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_crypto_.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 19:29:11 by ezalos            #+#    #+#             */
/*   Updated: 2020/03/31 19:29:11 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_CRYPTO__H
# define AUTO_CRYPTO__H

void		vct_print_bin_nl(t_vector *vector);
void		feistel_print_debug(char *name, t_vector *vct);
void		print_crypt(t_crypt *crypto);
int		main(int ac, char **av);
intmax_t	ft_seed_string(const char *str, size_t len);
t_crypt		*init(char *msg, char *key, t_feistel_hash hash_func);
void		apply_key(t_vector *msg, t_vector *key, t_vector *dest);
t_vector	*feistel(t_crypt *crypto);
void		clean_feistel(t_crypt **crypto);

#endif
