/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:43:33 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 11:46:35 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
