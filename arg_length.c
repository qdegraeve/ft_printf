/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:13:01 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/11 17:29:03 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_min_lenght(char *format, t_arg *a)
{
	if (format[a->i] == '0')
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
