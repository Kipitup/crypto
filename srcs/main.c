#include "head.h"

int		main(int ac, char **av)
{
	t_crypt		*crypto;

	if (ac > 4)
	{
//		ft_dprintf(STD_ERR, "------------------------------------\n");
		crypto = init(av[1], av[2], &apply_key, ft_atoi(av[3]), av[4]);
		if (crypto != NULL)
		{
			if (crypto->state == UNCRYPT)
			{
				int fd = open("msg_uncrypt", O_RDWR | O_CREAT | O_TRUNC, 0744);
				ft_dprintf(fd, "%s", crypto->msg->str);
				system("diff cypher msg_uncrypt");
			}
			if (crypto->state == CRYPT || crypto->state == UNCRYPT)
			{
				crypto->cypher = feistel(crypto);
//				ft_dprintf(STD_ERR, "------------------------------------\n");
				write(1, crypto->cypher->str, crypto->cypher->len);
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
