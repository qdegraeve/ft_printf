/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:19:44 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 15:22:32 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_percent(t_arg *a)
{
	a->ret = 1;
	a->f_minest == 1 ? ft_putchar('%') : 0;
	while (a->ret < a->l_lenght)
	{
		ft_putchar(' ');
		a->ret++;
	}
	a->f_minest == 0 ? ft_putchar('%') : 0;
}

