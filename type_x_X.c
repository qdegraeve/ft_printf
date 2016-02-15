/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:41:21 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/15 20:41:47 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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

void	ft_repeat_char(char c, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		write(1, &c, 1);
		i++;
	}
}

void	type_x(char type, t_arg *a)
{
	char	*s;
	unsigned long x;

	x = va_arg(a->ap, unsigned long);
	if (!(x))
	{
		a->p_precision < a->l_lenght? ft_repeat_char(' ', a->l_lenght - a->p_precision) : 0;
		a->p_precision ? ft_repeat_char('0', a->p_precision) : 0;
		a->ret = a->p_precision > a->l_lenght ? a->p_precision : a->l_lenght;
		return ;
	}
	s = a->m_l || a->m_ll ? ft_ltoa_base(x, 16) : ft_utoa_base((unsigned int)x, 16);
	a->ret = a->f_hash ? ft_strlen(s) + 2 : ft_strlen(s);
	if (type == 'x')
		s = str_lower(s);
	(a->f_minest || a->l_zero) && a->f_hash && type == 'x' ? ft_putstr("0x") : 0;
	(a->f_minest || a->l_zero) && a->f_hash && type == 'X' ? ft_putstr("0X") : 0;
	a->f_minest ? ft_putstr(s) : 0;
	while (a->ret < a->l_lenght)
	{
		a->f_minest == 0 && a->l_zero == 1 ? ft_putchar('0') : ft_putchar(' ');
		a->ret++;
	}
	!a->f_minest && !a->l_zero && a->f_hash && type == 'x' ? ft_putstr("0x") : 0;
	!a->f_minest && !a->l_zero && a->f_hash && type == 'X' ? ft_putstr("0X") : 0;
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
