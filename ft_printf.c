/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 12:36:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/08 20:45:57 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	check_flags(char *format, t_arg *a)
{
	if (format[a->i] == '-')
	{
		a->f_minest = 1;
		(a->i)++;
	}
	if (format[a->i] == '+')
	{
		a->f_plus = 1;
		(a->i)++;
	}
	if (format[a->i] == ' ')
	{
		a->f_space = 1;
		(a->i)++;
	}
	if (format[a->i] == '#')
	{
		a->f_hash = 1;
		(a->i)++;
	}
	check_min_lenght(format, a);
}

void	check_min_lenght(char *format, t_arg *a)
{
	if (format[a->i] == 0)
	{
		a->l_zero = 1;
		(a->i)++;
	}
	if (format[a->i] > '0' && format[a->i] <= '9')
		a->l_lenght = ft_atoi(format + a->i);
	while (format[a->i] > '0' && format[a->i] <= '9')
		(a->i)++;
	if (format[a->i] == '.')
		check_precision(format, a);
	else
		check_modifier(format, a);
}

void	check_precision(char *format, t_arg *a)
{
	(a->i)++;
	if (format[a->i] > '0' && format[a->i] <= '9')
		a->p_precison = ft_atoi(format + a->i);
	else
	{
		ft_putendl("erreur formatage precision");
		exit(0);
	}
	while (format[a->i] > '0' && format[a->i] <= '9')
		(a->i)++;
}

void	check_modifier(char *format, t_arg *a)
{
	check_type(format, a);
}

void	check_type(char *format, t_arg *a)
{
	if (format[a->i] == 's' || format[a->i] == 'S')
		type_s(format[a->i], a);
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

void	convert_arg_d(int d)
{
	ft_putnbr(d);
}

void	ft_printf(char *format, ...)
{
	t_arg		a;
	va_list		ap;

	a.i = 0;
	va_start(ap, format);
	while (format[a.i])
	{
		if (format[a.i] == '%')
		{
			check_flags(format, &a);
		}
		else
			ft_putchar(format[a.i]);
		(a.i)++;
	}
	va_end(ap);
}

int	main(void)
{
	ft_printf("caca %d %s %c", 42, "boudin", 'p');
	return (0);
}
