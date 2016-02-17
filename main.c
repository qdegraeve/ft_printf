/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:28:02 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/17 14:33:41 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int i = 0;
	int j = 0;

	printf("int = {%lu} bytes\n", sizeof(int));
	printf("long = {%lu} bytes\n", sizeof(long));
	printf("unsigned long  = {%lu} bytes\n", sizeof(unsigned long));
	printf("double = {%lu} bytes\n", sizeof(double));
	printf("float = {%lu} bytes\n", sizeof(float));
	printf("long long = {%lu} bytes\n", sizeof(long long));
	printf("intmax_t = {%lu} bytes\n", sizeof(intmax_t));
	printf("uintmax_t = {%lu} bytes\n", sizeof(uintmax_t));
	printf("test_hash  s = [%s] x = [%#x] X = [%X] u = [%u]  o = [%#o] d = [%5d] i = [%i] f = [%#f]\n", "boudin", 0, 15, 15, -15, -15, -15, 42.42);
	ft_printf("pers_hash  s = [%s] x = [%#6.5x] X = [%X] u = [%u]  o = [%#o] d = [%010.5d] i = [%i] f = [%#f]\n", "boudin", 0, 15, 15, -15, -15, -15, 42.42);
	i = printf("ab_printf caca %.4s %#-10.5o %.9% %5c\n", "boudin", 2500, 'q');
	j = ft_printf("ft_printf caca %.4s %#-10.5o %.9% %5c\n", "boudin", 2500, 'q');
	printf("printf == {%d} ft_printf == {%d}\n", i, j);
	printf("printf == {%d} - {%ld}\n", (short int)32768, 9223372036854775806);
	ft_printf("ft_printf == {%d} - {%ld}\n", (short int)32768, 9223372036854775806);
	return (0);
}
