/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 12:48:27 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/19 20:19:49 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_p(t_arg *a)
{
	char				*s;

	s = ft_utoa_base(va_arg(a->ap, unsigned long long), 16);
	if (s[0] == '0')
		s[0] = 0;
	a->ret = ft_strlen(s);
	while (a->ret < a->p)
	{
		s = ft_cjoin(ft_strdup("0"), s);
		a->ret++;
	}
	s = ft_cjoin(ft_strdup("0x"), s);
	a->ret += 2;
	while (a->ret < a->l)
	{
		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		a->ret++;
	}
	a->ret = ft_strlen(s);
	s = str_lower(s);
	ft_putstr(s);
	ft_strdel(&s);
}
