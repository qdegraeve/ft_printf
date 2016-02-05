/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 12:36:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/05 14:22:49 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void foo(char *fmt, ...)
{
	va_list		ap;
	va_list		ap2;
	int			d;
	char		c;
	char		*s;

	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (*fmt)
		switch(*fmt++) {
			case 's':                       /* string */
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':                       /* int */
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':                       /* char */
				/* Note: char is promoted to int. */
				c = va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	va_end(ap);
		/* use ap2 to iterate over the arguments again */
	va_end(ap2);
}
