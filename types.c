/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:14:44 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/11 21:21:16 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type(char *format, t_arg *a)
{
	if (format[a->i] == 's' || format[a->i] == 'S')
		type_s(format[a->i], a);
	if (format[a->i] == 'd' || format[a->i] == 'i')
		type_d(format[a->i], a);
	if (format[a->i] == '%')
		type_percent(a);
	if (format[a->i] == 'x' || format[a->i] == 'X')
		type_x(a);
	if (format[a->i] == 'o')
		type_o(a);
	if (format[a->i] == 'u')
		type_u(a);
}
