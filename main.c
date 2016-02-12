/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:28:02 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 16:32:12 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = 0;
	int j = 0;

	i = printf("ab_printf caca %d %- 5d %.5%\n", "boudin", 14);
	j = ft_printf("ft_printf caca %d %- 5d %.5%\n", "boudin", 14);
	printf("printf == {%d} ft_printf == {%d}\n", i, j);
	return (0);
}
