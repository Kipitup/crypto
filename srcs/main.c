#include "head.h"

uint8_t		get_state(char *str)
{
	t_vector	*str_state;

	str_state = vct_newstr(str);
	if (vct_strequ(str_state, "CRYPT") == TRUE)
		return (CRYPT);
	else if (vct_strequ(str_state, "UNCRYPT") == TRUE)
		return (UNCRYPT);
	else
		return (3);
}

int		main(int ac, char **av)
{
	t_crypt		*crypto;
	uint8_t		state;

	if (ac > 4)
	{
		crypto = init(av[1], av[2], &apply_key, ft_atoi(av[3]));
		if (crypto != NULL)
		{
			state = get_state(av[4]);
			//if (state == CRYPT)
			//	ft_dprintf(STD_ERR, "{c_red}%s{c_end}", crypto->msg->str);
			if (state == CRYPT || state == UNCRYPT)
			{
				crypto->cypher = feistel(crypto, state);
				ft_printf("%s", crypto->cypher->str);
			}
			else
				ft_printf("Usage: %s to_crypt key [CRYPT / UNCRYPT]\n", av[0]);
		}
		clean_feistel(&crypto);
	}
	else
		ft_printf("Usage: %s to_crypt key [CRYPT / UNCRYPT]\n", av[0]);
	return (0);
}
