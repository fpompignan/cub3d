/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:36:30 by douattar          #+#    #+#             */
/*   Updated: 2021/11/29 13:34:12 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)s;
	while (i < n)
	{
		if ((unsigned char)copy[i] == (unsigned char)c)
			return (copy + i);
		i++;
	}
	return (0);
}
