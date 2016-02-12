/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:39:10 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 15:05:53 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	type_d(char type, t_arg *a)
{
	int d;
	int tmp;

	d = 0;
	if (type == 'd' || type == 'i')
		d = va_arg(a->ap, int);
	a->ret = d < 0 || a->f_plus || a->f_space ? 2 : 1;
	tmp = d;
	while ((tmp = tmp / 10))
		a->ret++;
	a->f_minest && a->f_plus && d >= 0 ? ft_putchar('+') : 0;
	a->f_minest && a->f_space && d >= 0  && !a->f_plus ? ft_putchar(' ') : 0;
	a->f_minest ? ft_putnbr(d) : 0;
	while (a->ret < a->l_lenght)
	{
		a->f_minest == 0 && a->l_zero == 1 ? ft_putchar('0') : ft_putchar(' ');
		a->ret++;
	}
	!a->f_minest && a->f_plus && d >= 0 ? ft_putchar('+') : 0;
	!a->f_minest && a->f_space && d >= 0  && !a->f_plus ? ft_putchar(' ') : 0;
	!a->f_minest ? ft_putnbr(d) : 0;
}
