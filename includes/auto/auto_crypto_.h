/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_crypto_.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezalos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 14:01:59 by ezalos            #+#    #+#             */
/*   Updated: 2020/04/12 14:01:59 by ezalos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_CRYPTO__H
# define AUTO_CRYPTO__H

void		vct_print_bin_nl(t_vector *vector);
void		feistel_print_debug(char *name, t_vector *vct);
void		print_feistel_cycle(t_vector *sub_key, t_vector *hash_output,
		t_vector *left, size_t i, int8_t state);
void		print_crypt(t_crypt *crypto);
t_crypt		*init(char *msg, char *key, t_feistel_hash hash_func,
		size_t cycles, char *str_state);
int8_t		get_state(char *str);
t_vector	*get_arg(char *arg);
int		main(int ac, char **av);
intmax_t	ft_seed_string(const char *str, size_t len);
void		clean_feistel(t_crypt **crypto);
void		apply_xor(t_vector *dest, t_vector *to_xor_with);
void		apply_key(t_vector *msg, t_vector *key, t_vector *dest);
t_vector	*feistel(t_crypt *crypto);
t_crypt		*feistel_cypher(char *msg, char *key, t_feistel_hash hash_func,
		size_t cycles, char *str_state);
void		next_key(t_vector *sub_key, size_t cycle);

#endif
