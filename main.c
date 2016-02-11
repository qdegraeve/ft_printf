/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:28:02 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/11 17:26:41 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = 0;
	int j = 0;

	i = printf("ab_printf caca %s %d %%\n", "boudin", 424242);
	j = ft_printf("ft_printf caca %s %d %%\n", "boudin", 424242);
	printf("printf == {%d} ft_printf == {%d}\n", i, j);
	return (0);
}
