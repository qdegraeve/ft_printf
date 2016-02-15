/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:14:44 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/15 21:36:29 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type(char *format, t_arg *a)
{
	set_default_precision(format[a->i], a);
	if (format[a->i] == 's' || format[a->i] == 'S')
		type_s(format[a->i], a);
	else if (format[a->i] == 'd' || format[a->i] == 'i')
		type_d(format[a->i], a);
	else if (format[a->i] == '%')
		type_percent(a);
	else if (format[a->i] == 'x' || format[a->i] == 'X')
		type_x(format[a->i], a);
	else if (format[a->i] == 'o')
		type_o(a);
	else if (format[a->i] == 'u')
		type_u(a);
	else if (format[a->i] == 'f')
		type_f(a);
	else if (format[a->i] == 'c')
		type_c(a);
	else
		ft_putchar(format[a->i]);
}
