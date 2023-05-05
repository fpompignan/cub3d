/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:49:24 by douattar          #+#    #+#             */
/*   Updated: 2021/12/02 09:33:08 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int count)
{
	int		i;	
	char	*cast;
	char	*cast2;

	cast = (char *)dest;
	cast2 = (char *)src;
	if (src == dest || count == 0)
		return (dest);
	else if (src > dest)
	{
		i = -1;
		while (++i < count)
			cast[i] = cast2[i];
	}
	else if (src < dest)
	{
		i = count;
		while (i-- > 0)
			cast[i] = cast2[i];
	}
	return (cast);
}
