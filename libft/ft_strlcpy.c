/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:02:35 by douattar          #+#    #+#             */
/*   Updated: 2021/12/03 17:06:25 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, long unsigned int size)
{
	int	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[i] && i != (int)size)
	{
		dst[i] = src[i];
		i++;
	}
	if (i == (int)size)
		i--;
	dst[i] = '\0';
	return ((ft_strlen(src)));
}
