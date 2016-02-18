/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:03:40 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/18 16:42:44 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_s(t_arg *a)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	if (!(s = va_arg(a->ap, char *)))
		s = ft_strdup("(null)");
	if (!s[0])
		ft_repeat_char(' ', a->l);
	a->ret = !s[0] || a->p == 0 ? a->l : ft_strlen(s);
	i = a->p >= 0 && a->p < a->ret ? a->l - a->p : a->l - a->ret;
	!a->f_m && s[0] ? ft_repeat_char(' ', i) : 0;
	if (a->p > 0 && s[0])
	{
		a->p < a->ret ? a->ret = a->p : 0;
		while (s[j] && a->p--)
			ft_putchar(s[j++]);
	}
	else
		a->p == -1 ? ft_putstr(s) : 0;
	a->f_m && s[0] ? ft_repeat_char(' ', i) : 0;
	if (i > 0 && s[0] && a->p != 0)
		a->ret += i;
	ft_strdel(&s);
}

void	type_s_ls(char type, t_arg *a)
{
	if (type == 's')
		type_s(a);
	else
		va_arg(a->ap, wchar_t*);
}
