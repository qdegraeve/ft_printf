/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:14:44 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/18 17:24:04 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type(char *format, t_arg *a)
{
	set_default_precision(format[a->i], a);
	if (format[a->i] == 's' || format[a->i] == 'S')
		type_s_ls(format[a->i], a);
	else if (format[a->i] == 'd' || format[a->i] == 'i' || format[a->i] == 'D')
		type_d(format[a->i], a);
	else if (format[a->i] == '%')
		type_percent(a);
	else if (format[a->i] == 'x' || format[a->i] == 'X')
		type_x(format[a->i], a);
	else if (format[a->i] == 'o' || format[a->i] == 'O')
		type_o(format[a->i], a);
	else if (format[a->i] == 'u' || format[a->i] == 'U')
		type_u(format[a->i], a);
	else if (format[a->i] == 'f')
		type_f(a);
	else if (format[a->i] == 'c' || format[a->i] == 'C')
		type_c_lc(format[a->i], a);
	else
	{
		ft_putchar(format[a->i]);
		a->ret++;
	}
}
