/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:13:01 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/17 11:55:52 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_min_lenght(char *format, t_arg *a)
{
	if (format[a->i] > '0' && format[a->i] <= '9')
		a->l = ft_atoi(format + a->i);
	while (format[a->i] >= '0' && format[a->i] <= '9')
		a->i++;
	if (format[a->i] == '.')
		check_precision(format, a);
	else
		check_modifier(format, a);
}

void	check_precision(char *format, t_arg *a)
{
	a->i++;
	if (format[a->i] >= '0' && format[a->i] <= '9')
		a->p = ft_atoi(format + a->i);
	else
		a->p = 0;
	while (format[a->i] >= '0' && format[a->i] <= '9')
		a->i++;
	check_modifier(format, a);
}

void	set_default_precision(char type, t_arg *a)
{
	if (a->p == -1 && type != 'd' && type != 'i')
	{
		a->p = type == 'c' || type == 's' || type == 'S' ? 0 : 1;
		if (type == 'f' || type == 'e' || type == 'E' || type == 'g' ||
				type == 'G')
			a->p = 6;
	}
}
