/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:56:05 by douattar          #+#    #+#             */
/*   Updated: 2021/12/04 10:57:34 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	puissance;
	int	end;

	i = 0;
	res = 0;
	puissance = 1;
	end = 0;
	while ((7 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	end = i;
	while ('0' <= nptr[i] && nptr[i] <= '9')
		i++;
	while (i-- > end)
	{
		res += ((char)nptr[i] - '0') * puissance;
		puissance *= 10;
	}
	if (end > 0 && nptr[end - 1] == '-')
		return (-res);
	return ((int)(res));
}
