/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:06:10 by fkante            #+#    #+#             */
/*   Updated: 2020/03/12 11:52:12 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define_pf.h"

static void	itoa_exception(uint64_t value, char *ptr, uint64_t flag)
{
	if (value == 0)
		ptr[0] = '0';
	else if ((value == 4294967296) && (flag & FLAG_L))
		ft_strcpy(ptr, "100000000");
	else if ((value == 4294967296) && ((flag & FLAG_LL && flag & CONV_X_MAJ)
				|| (flag & CONV_X && flag & FLAG_J)))
		ft_strcpy(ptr, "100000000");
	else if ((value == 4294967296) && (flag & CONV_X))
		ft_strcpy(ptr, "0");
}

char		*ft_u_itoa_base(uint64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;

	base_str = "0123456789abcdef";
	ptr = NULL;
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (len > 0)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}

char		*ft_itoa_base(int64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	int64_t		nb;
	size_t		len;

	base_str = "0123456789abcdef";
	ptr = NULL;
	nb = value;
	len = ft_int64_t_len(nb, base);
	nb = ft_absolute(nb);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		if (value == LLONG_MIN)
			return (ft_strcpy(ptr, "-9223372036854775808"));
		while (nb)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value < 0 && base == 10)
			ptr[0] = '-';
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}

char		*ft_itoa_base_maj(uint64_t value, uint8_t base, uint64_t flag)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;

	base_str = "0123456789ABCDEF";
	ptr = NULL;
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (len > 0)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		itoa_exception(value, ptr, flag);
	}
	return (ptr);
}

char		*ft_ox_itoa_base(uint64_t value, uint8_t base, uint64_t flag)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;

	base_str = "0123456789abcdef";
	ptr = NULL;
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (len > 0)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		itoa_exception(value, ptr, flag);
	}
	return (ptr);
}
