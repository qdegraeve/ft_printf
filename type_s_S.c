/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_S.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:40:55 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/15 18:29:24 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_s(char type, t_arg *a)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	type = 's';
	s = va_arg(a->ap, char *);
	if (!s[0])
	{
		ft_repeat_char(' ', a->l_lenght);
		a->ret = a->l_lenght;
		return ;
	}
	a->ret = ft_strlen(s);
	i = a->p_precision > 0 ? a->l_lenght - a->p_precision : a->l_lenght - a->ret;
	!a->f_minest ? ft_repeat_char(' ', i) : 0;
	if (a->p_precision)
	{
		a->ret = a->p_precision;
		while (a->p_precision--)
			ft_putchar(s[j++]);
	}
	else
		ft_putstr(s);
	a->f_minest ? ft_repeat_char(' ', i) : 0;
	if (i > 0)
		a->ret += i;
}
