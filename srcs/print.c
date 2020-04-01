#include "head.h"

void	vct_print_bin_nl(t_vector *vector)
{
	size_t		i;

	if (vector != NULL && vector->str != NULL)
	{
		ft_printf("%d ", vector->len);
		ft_printf("[");
		vct_print(vector);
		ft_printf("]");
		i = 0;
		if (vector->len < MAX_LEN_PRINT)
		{
			while (i < MAX_LEN_PRINT - vector->len)
			{
				ft_printf(" ");
				i++;
			}
		}
		ft_printf("\t");
		i = 0;
		while (i < vector->len)
		{
			ft_printf("%0b ", 2, vector->str[i++]);
		}
		ft_printf("\n");
	}
}

void	feistel_print_debug(char *name, t_vector *vct)
{
	ft_printf("%-*s : ", MAX_LEN_PRINT, name);
	vct_print_bin_nl(vct);
}

void	print_crypt(t_crypt *crypto)
{
	ft_printf("{c_green}");
	feistel_print_debug("message", crypto->msg);
	ft_printf("{c_blue}");
	feistel_print_debug("key", crypto->key);
	ft_printf("{c_red}");
	feistel_print_debug("cypher", crypto->cypher);
	ft_printf("{c_end}");
}
