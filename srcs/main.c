#include "head.h"

int		main(int ac, char **av)
{
	t_crypt		*crypto;
	int			fd;
	
	if (ac > 4)
	{
		crypto = init(av[1], av[2], &apply_key, ft_atoi(av[3]), av[4]);
		if (crypto != NULL)
		{
			if (crypto->state == UNCRYPT)
			{
				int fd_tmp = open("msg_crypt", O_RDWR | O_CREAT | O_TRUNC, 0744);
				vct_dprint(fd_tmp, crypto->msg);
				system("diff -a cypher msg_crypt");
			}
			if (crypto->state == CRYPT || crypto->state == UNCRYPT)
			{
				crypto->cypher = feistel(crypto);
				if (crypto->state == CRYPT)
					fd = open("cypher", O_RDWR | O_CREAT | O_TRUNC, 0744);
				else
					fd = open("uncrypt_msg", O_RDWR | O_CREAT | O_TRUNC, 0744);
				vct_dprint(fd, crypto->cypher);
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
