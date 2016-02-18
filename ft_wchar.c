/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:14:23 by qdegraev          #+#    #+#             */
/*   Updated: 2016/02/18 20:45:59 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	masks_fill(char *mask, char *wc)
{
	int		mlen;
	int		wlen;

	mlen = ft_strlen(mask) - 1;
	wlen = ft_strlen(wc) - 1;
	while (mlen)
	{
		while (mask[mlen] != 'x' && mlen)
		{
			mlen--;
		}
		if (wlen >= 0)
			mask[mlen--] = wc[wlen--];
		wlen == -1 && mask[mlen] == 'x' ? mask[mlen--] = '0' : 0;
	}
	printf("\nmlen = %d\n", mlen);
}

void	unicode_masks(char *wc)
{
	char	*m;
		
	if (ft_strlen(wc) <= 7)
		masks_fill(m = ft_strdup("0xxxxxxx"), wc);
	else if (ft_strlen(wc) <= 11)
		masks_fill(m = ft_strdup("110xxxxx10xxxxxx"), wc);
	else if (ft_strlen(wc) <= 16)
		masks_fill(m = ft_strdup("1110xxxx10xxxxxx10xxxxxx"), wc);
	else
		masks_fill(m = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx"), wc);
	ft_putendl(m);
	free(m);

}
