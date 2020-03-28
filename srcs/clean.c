#include "head.h"

void	clean_feistel(t_crypt **crypto)
{
	if (crypto != NULL && *crypto != NULL)
	{
		vct_del(&((*crypto)->msg));
		vct_del(&((*crypto)->key));
		ft_memdel((void**)crypto);
	}
}
