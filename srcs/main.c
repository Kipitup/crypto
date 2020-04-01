#include "head.h"

t_vector	*ft_get_file(int fd)
{
	t_vector	*file;
	t_vector	*line;
	int8_t		ret;

	line = NULL;
	file = vct_new(DEFAULT_VCT_SIZE);
	while ((ret = vct_read_line(fd, &line)) > 0)
	{
		ret = vct_addchar(line, '\n');
		if (ret == SUCCESS)
			ret = vct_cat(file, line);
		vct_del(&line);
		if (ret == FAILURE)
			break ;
	}
	vct_read_line(CLEANUP, &line);
	if (ret == FAILURE)
		vct_del(&file);
	return (file); 
}

int		main(int ac, char **av)
{
	t_crypt		*crypto;
	t_vector	*file;
	int			fd;

	if (ac > 2)
	{
		crypto = init(av[1], av[2], &apply_key);
		if (crypto != NULL)
		{
			fd = open(av[1], O_RDWR, 744);
			if (fd != FAILURE)
			{
				file = ft_get_file(fd);
				vct_del(&(crypto->msg));
				crypto->msg = file;
			}
			crypto->cypher = feistel(crypto, CRYPT);
			print_crypt(crypto);
			ft_printf("\n\n\n");
			crypto->msg = crypto->cypher;
			crypto->cypher = feistel(crypto, UNCRYPT);
			print_crypt(crypto);
		}
		clean_feistel(&crypto);
	}
	return (0);
}
