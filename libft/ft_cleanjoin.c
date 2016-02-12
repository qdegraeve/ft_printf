/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 19:45:08 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/12 19:55:01 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cleanjoin(char *s1, char *s2)
{
	char	*stock;

	if (s1 == NULL  && s2 == NULL)
		return (NULL);
	stock = ft_strjoin(s1, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	return (stock);
}
