/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 12:36:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 16:29:37 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	check_modifier(char *f, t_arg *a)
{
	if (f[a->i] == 'h' || f[a->i] == 'l' || f[a->i] == 'j' || f[a->i] == 'z')
	{
		if (f[a->i] == 'h' && f[a->i + 1] == 'h')
			a->hh_modifier = 1;
		else if (f[a->i] == 'h')
			a->h_modifier = 1;
		else if (f[a->i] == 'l' && f[a->i + 1] == 'l')
			a->ll_modifier = 1;
		else if (f[a->i] == 'l')
			a->l_modifier = 1;
		else if (f[a->i] == 'j')
			a->j_modifier = 1;
		else if (f[a->i] == 'z')
			a->z_modifier = 1;
		a->i = a->ll_modifier || a->hh_modifier ? a->i + 2 : a->i + 1;
	}
	check_type(f, a);
}

void	type_s(char type, t_arg *a)
{
	char *s;

	s = va_arg(a->ap, char *);
	a->ret = ft_strlen(s);
	if (type == 's')
		ft_putstr(s);
	if (type == 'S')
		ft_putstr(s);
}

void	type_o(t_arg *a)
{
	char *s;

	s = ft_utoa_base(va_arg(a->ap, unsigned int), 8);
	a->ret = ft_strlen(s);
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

void	init_struct(t_arg *a)
{
	a->ret = 0;
	a->f_plus = 0;
	a->f_minest = 0;
	a->f_space = 0;
	a->f_hash = 0;
	a->f_none = 0;
	a->l_zero = 0;
	a->l_lenght = 0;
	a->p_precision = 0;
}

int		ft_printf(char *format, ...)
{
	t_arg		a;
	int			ret;

	ret = 0;
	a.i = 0;
	va_start(a.ap, format);
	while (format[a.i])
	{
		init_struct(&a);
		if (format[a.i] == '%')
		{
			a.i++;
			check_flags(format, &a);
		}
		else
		{
			ft_putchar(format[a.i]);
			ret++;
		}
		ret += a.ret;
		a.i++;
	}
	va_end(a.ap);
	return (ret);
}
