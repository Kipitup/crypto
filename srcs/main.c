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

uint8_t		get_state(char *str)
{
	t_vector	*str_state;
	uint8_t		state;

	(void)str_state;
	(void)state;
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
			if (state == CRYPT || state == UNCRYPT)
			{
				crypto->cypher = feistel(crypto, state);
				ft_printf("%s", crypto->cypher->str);
			}
			else
				ft_printf("Wrong state.\nUsage: %s to_crypt key [CRYPT / UNCRYPT]\n", av[0]);
		}
		clean_feistel(&crypto);
	}
	else
		ft_printf("Usage: %s to_crypt key [CRYPT / UNCRYPT]\n", av[0]);
	return (0);
}
