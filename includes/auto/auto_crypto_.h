#ifndef AUTO_CRYPTO__H
# define AUTO_CRYPTO__H

t_vector	*feistel(t_crypt *to_crypt);
void		rot(t_vector *vct, int rot);
t_crypt		*init(char *msg, char *key, t_fgteistel_hash hash_func);
int		main(int ac, char **av);
void		clean_feistel(t_crypt **crypto);
vct_func();

#endif
