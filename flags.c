/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 12:11:48 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/15 21:48:06 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char *f, t_arg *a)
{
	while (f[a->i] == '-' || f[a->i] == '+' || f[a->i] == ' ' || f[a->i] == '#' || f[a->i] == '0')
	{
		if (f[a->i] == '-')
			a->f_minest = 1;
		if (f[a->i] == '+')
			a->f_plus = 1;
		if (f[a->i] == ' ')
			a->f_space = 1;
		if (f[a->i] == '#')
			a->f_hash = 1;
		if (f[a->i] == '0')
			a->l_zero = 1;
		if (f[a->i + 1] != '\0')
			a->i++;
		else
			return;
	}
	check_min_lenght(f, a);
}
