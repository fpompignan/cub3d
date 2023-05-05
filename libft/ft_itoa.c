/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:53:11 by douattar          #+#    #+#             */
/*   Updated: 2021/12/03 18:45:25 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	length_number(int n)
{
	if (n < 10 && n > -10)
		return (1 + (n < 0));
	else
		return (length_number(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			taille;
	int			temp;

	taille = length_number(n);
	res = (char *)malloc(sizeof(char) * (taille + 1));
	if (!res)
		return ((char *)(0));
	res[taille] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (n < 0)
		res[0] = '-';
	while (n != 0)
	{
		temp = n % 10;
		if (temp < 0)
			temp = -temp;
		res[--taille] = temp + '0';
		n /= 10;
	}
	return (res);
}
