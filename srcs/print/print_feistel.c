#include "head.h"

void	vct_print_bin_nl(t_vector *vector)
{
//	size_t		i;

	if (vector != NULL && vector->str != NULL)
	{
		ft_dprintf(STD_ERR, "[%zu] ", vector->len);
		ft_dprintf(STD_ERR, "|");
		write(2, vector->str, vector->len);
		ft_dprintf(STD_ERR, "|");
//		i = 0;
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

void	print_feistel_cycle(t_vector *sub_key, t_vector *hash_output,
		t_vector *left, size_t i, int8_t state)
{
	ft_dprintf(STD_ERR, "{c_red} ---- CYCLE %zu ----{c_end}\n", i);

	ft_dprintf(STD_ERR, "%-*s : ", MAX_LEN_PRINT, "0 Key");
	(state == CRYPT) ? ft_dprintf(STD_ERR, "{c_magenta}") : ft_dprintf(STD_ERR, "{c_cyan}");
	vct_print_bin_nl(sub_key);
	ft_dprintf(STD_ERR, "{c_end}");
	
	ft_dprintf(STD_ERR, "%-*s : ", MAX_LEN_PRINT, "1 Right ^ Key = hash_output");
	(state == CRYPT) ? ft_dprintf(STD_ERR, "{c_magenta}") : ft_dprintf(STD_ERR, "{c_cyan}");
	vct_print_bin_nl(hash_output);
	ft_dprintf(STD_ERR, "{c_end}");
	
	ft_dprintf(STD_ERR, "%-*s : ", MAX_LEN_PRINT, "2 Left ^ hash_output");
	(state == CRYPT) ? ft_dprintf(STD_ERR, "{c_magenta}") : ft_dprintf(STD_ERR, "{c_cyan}");
	vct_print_bin_nl(left);
	ft_dprintf(STD_ERR, "{c_end}");
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
