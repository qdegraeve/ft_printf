/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:41:21 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/17 17:13:59 by qdegraev         ###   ########.fr       */
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
		a->p < a->l? ft_repeat_char(' ', a->l - a->p) : 0;
		a->p ? ft_repeat_char('0', a->p) : 0;
		a->ret = a->p > a->l ? a->p : a->l;
		return ;
	}
	s = a->m_l || a->m_ll ? ft_ltoa_base(x, 16) : ft_utoa_base((unsigned int)x, 16);
	a->ret = a->f_hash ? ft_strlen(s) + 2 : ft_strlen(s);
	if (type == 'x')
		s = str_lower(s);
	(a->f_m || a->f_zero) && a->f_hash && type == 'x' ? ft_putstr("0x") : 0;
	(a->f_m || a->f_zero) && a->f_hash && type == 'X' ? ft_putstr("0X") : 0;
	a->f_m ? ft_putstr(s) : 0;
	while (a->ret < a->l)
	{
		a->f_m == 0 && a->f_zero == 1 ? ft_putchar('0') : ft_putchar(' ');
		a->ret++;
	}
	!a->f_m && !a->f_zero && a->f_hash && type == 'x' ? ft_putstr("0x") : 0;
	!a->f_m && !a->f_zero && a->f_hash && type == 'X' ? ft_putstr("0X") : 0;
	a->f_m == 0 ? ft_putstr(s) : 0;
}
