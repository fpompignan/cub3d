/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:54:17 by douattar          #+#    #+#             */
/*   Updated: 2021/11/30 15:33:25 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	unsigned char	*copy1;
	unsigned char	*copy2;
	int				i;

	i = 0;
	if (!n)
		return (n);
	copy1 = (unsigned char *)(s1);
	copy2 = (unsigned char *)(s2);
	while (i < n && copy1[i] == copy2[i])
		i++;
	if (i == n)
		i--;
	return (copy1[i] - copy2[i]);
}
