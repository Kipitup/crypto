#include "head.h"

void	vct_print_bin_nl(t_vector *vector)
{
	size_t		i;

	if (vector != NULL && vector->str != NULL)
	{
		ft_dprintf(STD_ERR, "%d ", vector->len);
		ft_dprintf(STD_ERR, "[");
		write(2, vector->str, vector->len);
		ft_dprintf(STD_ERR, "]");
		i = 0;
//		if (vector->len < MAX_LEN_PRINT)
//		{
//			while (i < MAX_LEN_PRINT - vector->len)
//			{
//				ft_dprintf(STD_ERR, " ");
//				i++;
//			}
//		}
//		ft_dprintf(STD_ERR, "\t");
//		i = 0;
//		while (i < vector->len)
//		{
//			ft_dprintf(STD_ERR, "%0b ", 2, vector->str[i++]);
//		}
		ft_dprintf(STD_ERR, "\n");
	}
}

void	feistel_print_debug(char *name, t_vector *vct)
{
	ft_dprintf(STD_ERR, "%-*s : ", MAX_LEN_PRINT, name);
	vct_print_bin_nl(vct);
}

void	print_crypt(t_crypt *crypto)
{
	ft_dprintf(STD_ERR, "{c_green}");
	feistel_print_debug("message", crypto->msg);
	ft_dprintf(STD_ERR, "{c_blue}");
	feistel_print_debug("key", crypto->key);
	ft_dprintf(STD_ERR, "{c_red}");
	feistel_print_debug("cypher", crypto->cypher);
	ft_dprintf(STD_ERR, "{c_end}");
}
