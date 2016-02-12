/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:28:02 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 20:32:01 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = 0;
	int j = 0;

	printf("dtoa = {%s}\n", ft_dtoa_base(40.5464573, 10));
	printf("int = {%lu} bytes\n", sizeof(int));
	printf("long = {%lu} bytes\n", sizeof(long));
	printf("unsigned long  = {%lu} bytes\n", sizeof(unsigned long));
	printf("double = {%lu} bytes\n", sizeof(double));
	printf("float = {%lu} bytes\n", sizeof(float));
	printf("long long = {%lu} bytes\n", sizeof(long long));
	printf("intmax_t = {%lu} bytes\n", sizeof(intmax_t));
	printf("uintmax_t = {%lu} bytes\n", sizeof(uintmax_t));
	i = printf("ab_printf caca %s %f %.5%\n", "boudin", 40.5464573);
	j = ft_printf("ft_printf caca %s %f %.5%\n", "boudin", 40.5464573);
	printf("printf == {%d} ft_printf == {%d}\n", i, j);
	return (0);
}
