/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:24:25 by fkante            #+#    #+#             */
/*   Updated: 2019/10/02 14:13:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_u_itoa(uint64_t value)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;
	uint8_t		base;

	base = 10;
	base_str = "0123456789";
	ptr = NULL;
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (nb)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}

char	*ft_ld_itoa(long double value)
{
	const char	*base_str;
	char		*ptr;
	int64_t		nb;
	size_t		len;

	base_str = "0123456789";
	ptr = NULL;
	nb = (int64_t)value;
	len = ft_int64_t_len(nb, 10);
	if (value < 0 && value > -1)
		len++;
	nb = ft_absolute(nb);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (nb)
		{
			ptr[--len] = base_str[nb % 10];
			nb = nb / 10;
		}
		if (nb == 0 && len > 0)
			ptr[--len] = '0';
		if (value < 0)
			ptr[0] = '-';
	}
	return (ptr);
}

char	*ft_d_itoa(double value)
{
	const char	*base_str;
	char		*ptr;
	int64_t		nb;
	size_t		len;

	base_str = "0123456789";
	ptr = NULL;
	nb = (int64_t)value;
	len = ft_int64_t_len(nb, 10);
	if (value < 0 && value > -1)
		len++;
	nb = ft_absolute(nb);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (nb)
		{
			ptr[--len] = base_str[nb % 10];
			nb = nb / 10;
		}
		if (nb == 0 && len > 0)
			ptr[--len] = '0';
		if (value < 0)
			ptr[0] = '-';
	}
	return (ptr);
}

char	*ft_itoa(int64_t value)
{
	const char	*base_str;
	char		*ptr;
	int64_t		nb;
	size_t		len;
	uint8_t		base;

	base = 10;
	base_str = "0123456789";
	ptr = NULL;
	nb = value;
	len = ft_int64_t_len(nb, base);
	nb = ft_absolute(nb);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (nb)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value < 0)
			ptr[0] = '-';
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}
