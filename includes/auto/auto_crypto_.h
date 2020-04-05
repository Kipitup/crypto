#ifndef AUTO_CRYPTO__H
# define AUTO_CRYPTO__H

void		apply_key(t_vector *msg, t_vector *key, t_vector *dest);
void		vct_print_bin_nl(t_vector *vector);
void		feistel_print_debug(char *name, t_vector *vct);
void		print_feistel_cycle(t_vector *sub_key, t_vector *hash_output,
		t_vector *left, size_t i, int8_t state);
void		print_crypt(t_crypt *crypto);
int get_file_tmp(void);
t_vector	*ft_get_file(int fd);
int8_t		get_state(char *str);
t_crypt		*init(char *msg, char *key, t_feistel_hash hash_func, size_t cycles,
		char *str_state);
intmax_t	ft_seed_string(const char *str, size_t len);
void		next_key(t_vector *sub_key, size_t cycle);
t_vector	*feistel(t_crypt *crypto);
int		main(int ac, char **av);
void		clean_feistel(t_crypt **crypto);

#endif
