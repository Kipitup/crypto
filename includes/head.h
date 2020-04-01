#ifndef HEAD_H
# define HEAD_H

# include "libft.h"

# define FEISTEL_CYCLES	3	
# define MAX_LEN_PRINT		12
# define CRYPT				0
# define UNCRYPT			1

typedef void	(*t_feistel_hash)(t_vector *, t_vector *, t_vector *);

typedef struct 		s_crypt{
	t_vector 		*msg;
	t_vector 		*key;
	t_vector 		*cypher;
	t_feistel_hash	hash;
	size_t			nb_cycles;
}					t_crypt;

# include "auto_crypto.h"

#endif
