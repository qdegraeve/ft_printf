/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:28:02 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/22 13:15:54 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	int i = 0;
	int j = 0;

	setlocale(LC_ALL, "en_US.UTF-8");
	printf("int = {%lu} bytes\n", sizeof(int));
	printf("long = {%lu} bytes\n", sizeof(long));
	printf("unsigned long  = {%lu} bytes\n", sizeof(unsigned long));
	printf("double = {%lu} bytes\n", sizeof(double));
	printf("float = {%lu} bytes\n", sizeof(float));
	printf("long long = {%lu} bytes\n", sizeof(long long));
	printf("intmax_t = {%lu} bytes\n", sizeof(intmax_t));
	printf("uintmax_t = {%lu} bytes\n", sizeof(uintmax_t));
	printf("wchar_t * = {%lu} bytes\n", sizeof(wchar_t *));
	printf("wchar_t = {%lu} bytes\n", sizeof(wchar_t));
	printf("char = {%lu} bytes\n", sizeof(char));
	i = printf("vrai %4S %5p %#10.5x %5c\n", L"ÊM-^HM-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B", NULL, 250, 'q');
	j = ft_printf("faux %4S %5p %#10.5x %5c\n", L"ÊM-^HM-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B", NULL, 250, 'q');
	printf("printf == {%d} ft_printf == {%d}\n", i, j);
	i = printf("{vrai %*d}\n", 0, 0);
	j = ft_printf("{faux %*d}\n", 0, 0);
	printf("printf == {%d} ft_printf == {%d}\n", i, j);
	return (0);
}
