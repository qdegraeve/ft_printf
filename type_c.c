/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:37:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/15 16:56:05 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_c(t_arg *a)
{
	char	c;

	c = va_arg(a->ap, int);
	a->ret++;
	a->f_m ? ft_putchar(c) : 0;
	while (a->ret < a->l)
	{
		ft_putchar(' ');
		a->ret++;
	}
	!a->f_m ? ft_putchar(c) : 0;
}
