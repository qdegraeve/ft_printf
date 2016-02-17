/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:43:33 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/17 14:15:16 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_utoa_base(unsigned int value, int base)
{
	int		len;
	char	*ret;
	unsigned int		tmp;

	if (base < 2 || base > 16)
		return (NULL);
	len = 1;
	tmp = value;
	while ((tmp = tmp / base))
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0 && value / base != 0)
	{
		ret[len] = value % base < 10 ? value % base + '0' : value % base + '7';
		value /= base;
		len--;
	}
	ret[len--] = value % base < 10 ? value % base + '0' : value % base + '7';
	return (ret);
}

char	*ft_ltoa_base(long long value, int base)
{
	int		len;
	char	*ret;
	long long		tmp;

	if (base < 2 || base > 16)
		return (NULL);
	len = 1;
	tmp = value;
	while ((tmp = tmp / base))
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0 && value / base != 0)
	{
		ret[len] = value % base < 10 ? value % base + '0' : value % base + '7';
		value /= base;
		len--;
	}
	ret[len--] = value % base < 10 ? value % base + '0' : value % base + '7';
	return (ret);
}

char	*ft_dtoa_base(double value, int base, int precision, t_arg *a)
{
	char	*ret;
	double	tmp;

	if (base < 2 || base > 16)
		return (NULL);
	if (precision > 0)
	{
		ret = ft_cjoin(NULL, ft_itoa_base((int)value, base));
		tmp = value - (int)value;
		while ((value = value - (int)value) && precision > 0)
		{
			tmp = tmp * 10;
			value = tmp;
			precision--;
		}
		ret = ft_cjoin(ret, ft_strdup("."));
		ret = ft_cjoin(ret, ft_itoa_base(tmp, base));
	}
	else
	{
		value = (10 * (value - (int)value)) > 5 ? value + 1 : value;
		ret = a->f_hash ? ft_cjoin(ft_itoa_base((int)value, base),
				ft_strdup(".")) : ft_cjoin(NULL, ft_itoa_base((int)value,
					base));
	}
	return (ret);
}
