/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:37:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/18 17:32:22 by qdegraev         ###   ########.fr       */
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

void	type_c_lc(char type, t_arg *a)
{
	unsigned int	i;
	if (type == 'c')
		type_c(a);
	else
	{
		i = va_arg(a->ap, unsigned int);
		write(1, &i, 1);
		i = i << 8;
		write(1, &i, 1);
	}
}
