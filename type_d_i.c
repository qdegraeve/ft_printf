/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:39:10 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/17 12:03:38 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_d_std(int d, t_arg *a)
{
	char	*s;
	int		i;

	s = ft_itoa_base(ft_abs(d), 10);
	i = ft_strlen(s);
	a->ret = d < 0 || a->f_plus || a->f_space ? i + 1 : i;
	while (i++ < a->p_precision)
	{
		s = ft_cleanjoin(ft_strdup("0"), s);
		a->ret++;
	}
	s = a->f_plus && d >= 0 ? ft_cleanjoin(ft_strdup("+"), s) : s;
	s = a->f_space && d >= 0 && !a->f_plus ? ft_cleanjoin(ft_strdup(" "), s) : s;
	s = d < 0 ? ft_cleanjoin(ft_strdup("-"), s) : s;
	while (a->ret < a->l_lenght)
	{
		s = a->f_minest ? ft_cleanjoin(s, ft_strdup(" ")) : ft_cleanjoin(ft_strdup(" "), s);
		a->ret++;
	}
	return(s);
}

char	*type_d_zero(int d, t_arg *a)
{
	char	*s;
	int		i;

	s = ft_itoa_base(ft_abs(d), 10);
	i = ft_strlen(s);
	a->ret = d < 0 || a->f_plus || a->f_space ? i + 1 : i;
	if (a->p_precision != -1)
		while (i++ < a->p_precision && a->ret++ < a->l_lenght)
			s = ft_cleanjoin(ft_strdup("0"), s);
	else
		while (a->ret++ < a->l_lenght)
			s = ft_cleanjoin(ft_strdup("0"), s);
	a->ret--;
	s = a->f_plus && d >= 0 ? ft_cleanjoin(ft_strdup("+"), s) : s;
	s = a->f_space && d >= 0 && !a->f_plus ? ft_cleanjoin(ft_strdup(" "), s) : s;
	s = d < 0 ? ft_cleanjoin(ft_strdup("-"), s) : s;
	while (a->ret < a->l_lenght)
	{
		s = a->f_minest ? ft_cleanjoin(s, ft_strdup(" ")) : ft_cleanjoin(ft_strdup(" "), s);
		a->ret++;
	}
	return(s);
}

void	type_d(char type, t_arg *a)
{
	int		d;
	char	*s;

	d = 0;
	if (type == 'd' || type == 'i')
		d = va_arg(a->ap, int);
	s = a->l_zero ? type_d_zero(d, a) : type_d_std(d, a);
	ft_putstr(s);
}
