/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:25:39 by amartino          #+#    #+#             */
/*   Updated: 2020/03/09 21:26:27 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
**	This function will randomly fail to malloc
**
**	Since rand (r) is based on the time, it will be the same number for each
**	second. Since most of my program take less than a second, needed to add some
**I randomness with : res = (r * (int)ptr * (size / line)) % 5;
*/
void		*ft_malloc_debug(size_t size, const char *file, int line, const char *function)
{
	void	*ptr;
	srand(time(NULL)); 		  // Initialization, should only be called once.
	uint32_t r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
	uint32_t res;

	if (file != NULL && function != NULL)
		printf("Allocated bytes:\t%-10zu in %-40s at line %8d |\t%-20s\n", size, file, line, function);
	ptr = (void *)malloc(size);
	ft_bzero(ptr, size);
	res = (r * (int)ptr * (size / line)) % 5;
	printf("res %d\n", res);
	if (res == 0)
	{
		printf("FAILED\n");
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}
