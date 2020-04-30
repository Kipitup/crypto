#include "head.h"

void		apply_xor(t_vector *dest, t_vector *to_xor_with)
{
	size_t	i = 0;

	while (i < dest->len)
	{
		dest->str[i] ^= to_xor_with->str[i];
		i++;
	}
}
