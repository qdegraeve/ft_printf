/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 12:36:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/09 19:05:45 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	check_flags(char *f, t_arg *a)
{
	while (f[a->i] == '-' || f[a->i] == '+' || f[a->i] == ' ' || f[a->i] == '#')
	{
		if (f[a->i] == '-')
			a->f_minest = 1;
		if (f[a->i] == '+')
			a->f_plus = 1;
		if (f[a->i] == ' ')
			a->f_space = 1;
		if (f[a->i] == '#')
			a->f_hash = 1;
		a->i++;
	}
	check_min_lenght(f, a);
}

void	check_min_lenght(char *format, t_arg *a)
{
	if (format[a->i] == 0)
	{
		a->l_zero = 1;
		a->i++;
	}
	if (format[a->i] > '0' && format[a->i] <= '9')
		a->l_lenght = ft_atoi(format + a->i);
	while (format[a->i] > '0' && format[a->i] <= '9')
		a->i++;
	if (format[a->i] == '.')
		check_precision(format, a);
	else
		check_modifier(format, a);
}

void	check_precision(char *format, t_arg *a)
{
	a->i++;
	if (format[a->i] > '0' && format[a->i] <= '9')
		a->p_precison = ft_atoi(format + a->i);
	else
	{
		ft_putendl("erreur formatage precision");
		exit(0);
	}
	while (format[a->i] > '0' && format[a->i] <= '9')
		a->i++;
}

void	check_modifier(char *format, t_arg *a)
{
	check_type(format, a);
}

void	check_type(char *format, t_arg *a)
{
	if (format[a->i] == 's' || format[a->i] == 'S')
		type_s(format[a->i], a);
	if (format[a->i] == 'd' || format[a->i] == 'i')
		type_d(format[a->i], a);
}

void	type_s(char type, t_arg *a)
{
	if (type == 's')
		ft_putstr(va_arg(a->ap, char *));
	if (type == 'S')
		ft_putstr(va_arg(a->ap, char *));
}

void	convert_arg_s(char *s)
{
	ft_putstr(s);
}

void	convert_arg_c(char c)
{
	ft_putchar(c);
}

void	type_d(char type, t_arg *a)
{	
	int i;
	int d;
	int tmp;

	i = 1;
	d = 0;
	if (type == 'd' || type == 'i')
		d = va_arg(a->ap, int);
	tmp = d;
	while ((tmp = tmp / 10))
		i++;
	ft_putnbr(d);
	while (++i < a->l_lenght)
		ft_putchar(' ');
}

void	init_struct(t_arg *a)
{
	a->i = 0;
	a->f_plus = 0;
	a->f_minest = 0;
	a->f_space = 0;
	a->f_hash = 0;
	a->f_none = 0;
	a->l_zero = 0;
	a->l_lenght = 0;
	a->p_precison = 0;
}

void	ft_printf(char *format, ...)
{
	t_arg		a;

	init_struct(&a);
	va_start(a.ap, format);
	while (format[a.i])
	{
		if (format[a.i] == '%')
		{
			a.i++;
			check_flags(format, &a);
		}
		else
			ft_putchar(format[a.i]);
		a.i++;
	}
	va_end(a.ap);
}

int	main(void)
{
	ft_printf("ft_printf %-+-+2d boudin\n", -42);
	printf("ab_printf %-+-+2d boudin\n", -42);
	return (0);
}
