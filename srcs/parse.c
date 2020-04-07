#include "head.h"

int8_t		get_state(char *str)
{
	t_vector	*str_state;
	int8_t		state;

	state = FAILURE;
	str_state = vct_newstr(str);
	if (str_state != NULL)
	{	
		if (vct_strequ(str_state, "CRYPT") == TRUE)
			state = CRYPT;
		else if (vct_strequ(str_state, "DECRYPT") == TRUE)
			state = DECRYPT;
	}
	return (state);
}

t_vector	*get_arg(char *arg)
{
	t_vector	*file;
	int			fd;
	
	fd = open(arg, O_RDWR, 744);
	if (fd != FAILURE)
		file = vct_get_file(fd);
	else
		file = vct_newstr(arg);
	return (file);
}
