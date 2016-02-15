/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 12:36:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/15 21:42:08 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_modifier(char *f, t_arg *a)
{
	if (f[a->i] == 'h' || f[a->i] == 'l' || f[a->i] == 'j' || f[a->i] == 'z')
	{
		if (f[a->i] == 'h' && f[a->i + 1] == 'h')
			a->m_hh = 1;
		else if (f[a->i] == 'h')
			a->m_h = 1;
		else if (f[a->i] == 'l' && f[a->i + 1] == 'l')
			a->m_ll = 1;
		else if (f[a->i] == 'l')
			a->m_l = 1;
		else if (f[a->i] == 'j')
			a->m_j = 1;
		else if (f[a->i] == 'z')
			a->m_z = 1;
		a->i = a->m_ll || a->m_hh ? a->i + 2 : a->i + 1;
	}
	check_type(f, a);
}

void	type_o(t_arg *a)
{
	char	*s;
	unsigned long x;

	x = va_arg(a->ap, unsigned long);
	if (!(x))
	{
		a->p_precision < a->l_lenght? ft_repeat_char(' ', a->l_lenght - a->p_precision) : 0;
		a->p_precision ? ft_repeat_char('0', a->p_precision) : 0;
		a->ret = a->p_precision > a->l_lenght ? a->p_precision : a->l_lenght;
		return ;
	}
	s = a->m_l || a->m_ll ? ft_ltoa_base(x, 8) : ft_utoa_base((unsigned int)x, 8);
	if ((a->ret = ft_strlen(s)) < a->p_precision)
		while (a->ret < a->p_precision)
		{
			s = ft_cleanjoin(ft_strdup("0"), s);
			a->ret++;
		}
	else if (a->f_hash && a->ret++)
		s = ft_cleanjoin(ft_strdup("0"), s);
	a->f_minest ? ft_putstr(s) : 0;
	while (a->ret < a->l_lenght)
	{
		a->f_minest == 0 && a->l_zero == 1 ? ft_putchar('0') : ft_putchar(' ');
		a->ret++;
	}
	a->f_minest == 0 ? ft_putstr(s) : 0;
}

void	init_struct(t_arg *a)
{
	a->ret = 0;
	a->f_plus = 0;
	a->f_minest = 0;
	a->f_space = 0;
	a->f_hash = 0;
	a->f_none = 0;
	a->l_zero = 0;
	a->l_lenght = 0;
	a->m_hh = 0;
	a->m_h = 0;
	a->m_l = 0;
	a->m_ll = 0;
	a->m_j = 0;
	a->m_z = 0;
	a->p_precision = -1;
}

int		ft_printf(char *format, ...)
{
	t_arg		a;
	int			ret;

	ret = 0;
	a.i = 0;
	va_start(a.ap, format);
	while (format[a.i])
	{
		init_struct(&a);
		if (format[a.i] == '%')
		{
			if (format[a.i + 1] == '\0')
				break ;
			a.i++;
			check_flags(format, &a);
		}
		else
		{
			ft_putchar(format[a.i]);
			ret++;
		}
		ret += a.ret;
		a.i++;
	}
	va_end(a.ap);
	return (ret);
}
