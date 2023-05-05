/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:34:49 by douattar          #+#    #+#             */
/*   Updated: 2021/12/03 16:10:59 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int count)
{
	char	*cast;
	char	*cast2;
	int		i;

	if (count > 0 && (dest == NULL && src == NULL))
		return (dest);
	cast = (char *)dest;
	cast2 = (char *)src;
	i = 0;
	while (i < count)
	{
		cast[i] = cast2[i];
		i++;
	}
	return ((void *)(cast));
}
