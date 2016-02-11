/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:56:16 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/11 16:05:43 by qdegraev         ###   ########.fr       */
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
	int			p_precison;
}					t_arg;

/*		type conversion		*/

void				type_d(char type, t_arg *a);
void				type_s(char type, t_arg *a);
void				type_percent(t_arg *a);
void				convert_arg_s(char *s);
void				convert_arg_c(char c);
void				convert_arg_d(int);

/*		flags				*/

void				check_flags(char *format, t_arg *a);
void				check_min_lenght(char *format, t_arg *a);
void				check_precision(char *format, t_arg *a);
void				check_modifier(char *format, t_arg *a);

int					ft_printf(char *format, ...);
void				check_type(char *format, t_arg *a);

#endif
