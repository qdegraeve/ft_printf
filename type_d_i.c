/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:39:10 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/17 14:35:21 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_d_std(int d, t_arg *a)
{
	char	*s;
	int		i;

	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_ltoa_base(ft_abs(d), 10);
	i = ft_strlen(s);
	a->ret = d < 0 || a->f_p || a->f_sp ? i + 1 : i;
	while (i++ < a->p)
	{
		s = ft_cjoin(ft_strdup("0"), s);
		a->ret++;
	}
	s = a->f_p && d >= 0 ? ft_cjoin(ft_strdup("+"), s) : s;
	s = a->f_sp && d >= 0 && !a->f_p ? ft_cjoin(ft_strdup(" "), s) : s;
	s = d < 0 ? ft_cjoin(ft_strdup("-"), s) : s;
	while (a->ret < a->l)
	{
		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		a->ret++;
	}
	return(s);
}

char	*type_d_zero(int d, t_arg *a)
{
	char	*s;
	int		i;

	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_ltoa_base(ft_abs(d), 10);
	i = ft_strlen(s);
	a->ret = d < 0 || a->f_p || a->f_sp ? i + 1 : i;
	if (a->p != -1)
		while (i++ < a->p && a->ret++ < a->l)
			s = ft_cjoin(ft_strdup("0"), s);
	else
		while (a->ret++ < a->l)
			s = ft_cjoin(ft_strdup("0"), s);
	s = a->f_p && d >= 0 ? ft_cjoin(ft_strdup("+"), s) : s;
	s = a->f_sp && d >= 0 && !a->f_p ? ft_cjoin(ft_strdup(" "), s) : s;
	s = d < 0 ? ft_cjoin(ft_strdup("-"), s) : s;
	while (a->ret < a->l)
	{
		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		a->ret++;
	}
	return(s);
}

void	type_d(t_arg *a)
{
	long long	d;
	char		*s;

	d = va_arg(a->ap, long long);
	if (a->m_h)
		d = (short int)d;
	else if (a->m_hh)
		d = (signed char)d;
	else if (a->m_l)
		d = (long)d;
	else if (!a->m_ll)
		d = (int)d;
	s = a->f_zero && !a->f_m ? type_d_zero(d, a) : type_d_std(d, a);
	a->ret = ft_strlen(s);
	ft_putstr(s);
}
