#include "head.h"

void			next_key(t_vector *sub_key, size_t cycle)
{
	size_t		iteration;
	intmax_t	seed;
	size_t		i;

	iteration = 0;
	if (sub_key == NULL)
		return ;
	while (iteration < cycle)
	{
		i = 0;
		seed = ft_seed_string(sub_key->str, sub_key->len);
		srand(seed);
		while (i < sub_key->len)
		{
			vct_replace_char_at(sub_key, i, (char)rand());
			i++;
		}
		iteration++;
	}
}
