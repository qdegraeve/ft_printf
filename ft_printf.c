/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 12:36:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/11 21:34:08 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_modifier(char *format, t_arg *a)
{
	check_type(format, a);
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

void	type_percent(t_arg *a)
{
	ft_putchar('%');
	a->ret += 1;
	while (++(a->ret) < a->l_lenght)
	{
		ft_putchar(' ');
		a->ret++;
	}

}

void	type_x(t_arg *a)
{
	char *s;

	s = ft_itoa_base(va_arg(a->ap, unsigned int), 16);
	a->ret = ft_strlen(s);
	ft_putstr(s);
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
	ft_putnbru(u);
	while (++(a->ret) < a->l_lenght)
		ft_putchar(' ');
}

void	type_o(t_arg *a)
{
	char *s;

	s = ft_itoa_base(va_arg(a->ap, unsigned int), 8);
	a->ret = ft_strlen(s);
	ft_putstr(s);
}

void	type_d(char type, t_arg *a)
{
	int d;
	int tmp;

	d = 0;
	if (type == 'd' || type == 'i')
		d = va_arg(a->ap, int);
	tmp = d;
	while ((tmp = tmp / 10))
		a->ret++;
	ft_putnbr(d);
	while (++(a->ret) < a->l_lenght)
		ft_putchar(' ');
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
	a->p_precison = 0;
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
