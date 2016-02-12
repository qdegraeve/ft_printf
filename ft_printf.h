/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:56:16 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 16:17:55 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_arg
{
	va_list		ap;
	int			ret;
	int			i;
	int			f_plus;
	int			f_minest;
	int			f_space;
	int			f_hash;
	int			f_none;
	int			l_zero;
	int			l_lenght;
	int			p_precision;
	int			h_modifier;
	int			hh_modifier;
	int			l_modifier;
	int			ll_modifier;
	int			z_modifier;
	int			j_modifier;
}					t_arg;

/*		tools				*/

void				ft_putnbru(unsigned int nb);
char				*ft_utoa_base(unsigned int value, int base);

/*		type conversion		*/

void				type_d(char type, t_arg *a);
void				type_s(char type, t_arg *a);
void				type_x(char type, t_arg *a);
void				type_percent(t_arg *a);
void				type_u(t_arg *a);
void				type_o(t_arg *a);

/*		flags				*/

void				check_flags(char *format, t_arg *a);
void				check_min_lenght(char *format, t_arg *a);
void				check_precision(char *format, t_arg *a);
void				check_modifier(char *format, t_arg *a);

int					ft_printf(char *format, ...);
void				check_type(char *format, t_arg *a);

#endif
