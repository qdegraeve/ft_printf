/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:41:21 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 19:04:16 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_lower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

void	type_x(char type, t_arg *a)
{
	char	*s;

	s = a->m_l || a->m_ll ? ft_ltoa_base(va_arg(a->ap, unsigned long), 16) : ft_utoa_base(va_arg(a->ap, unsigned int), 16);
	a->ret = ft_strlen(s);
	if (type == 'x')
		s = str_lower(s);
	a->f_minest == 1 && a->f_plus == 1 ? ft_putchar('+') : 0;
	a->f_minest == 1 ? ft_putstr(s) : 0;
	while (a->ret < a->l_lenght)
	{
		a->f_minest == 0 && a->l_zero == 1 ? ft_putchar('0') : ft_putchar(' ');
		a->ret++;
	}
	a->f_minest == 0 && a->f_plus == 1 ? ft_putchar('+') : 0;
	a->f_minest == 0 ? ft_putstr(s) : 0;
}

void	type_u(t_arg *a)
{
	int u;
	int tmp;

	u = 0;
	u = va_arg(a->ap, int);
	tmp = u;
	while ((tmp = tmp / 10))
		a->ret++;
	a->f_minest == 1 && a->f_plus == 1 ? ft_putchar('+') : 0;
	a->f_minest == 1 ? ft_putnbru(u) : 0;
	while (a->ret < a->l_lenght)
	{
		a->f_minest == 0 && a->l_zero == 1 ? ft_putchar('0') : ft_putchar(' ');
		a->ret++;
	}
	a->f_minest == 0 && a->f_plus == 1 ? ft_putchar('+') : 0;
	a->f_minest == 0 ? ft_putnbru(u) : 0;
}
