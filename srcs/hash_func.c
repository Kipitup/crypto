#include "head.h"

void		apply_key(t_vector *msg, t_vector *key, t_vector *dest)
{
	size_t		i = 0;
	size_t		j;

	if (msg != NULL && msg->str != NULL)
	{
		dest->len = msg->len;
		while (i < msg->len)
		{
			j = 0;
			while ((j < key->len) && (i + j < msg->len))
			{
				dest->str[i + j] = (msg->str[i + j] ^ key->str[j]);
				j++;
			}
			i += j;
		}
	}
}
