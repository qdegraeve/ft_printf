/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_S.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:40:55 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 10:42:43 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
