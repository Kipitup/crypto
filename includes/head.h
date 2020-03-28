#ifndef HEAD_H
# define HEAD_H

# include "libft.h"
// # include "auto_project.h"

# define FEISTEL_CYCLES		1

typedef void	(*t_feistel_hash)(t_vector *, t_vector *);

typedef struct 		s_crypt{
	t_vector 		*msg;
	t_vector 		*key;
	t_vector 		*cypher;
	t_feistel_hash	hash;
	size_t			nb_cycles;
}					t_crypt;

void	clean_feistel(t_crypt **crypto);
#endif
