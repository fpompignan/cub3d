/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:23:43 by douattar          #+#    #+#             */
/*   Updated: 2021/12/02 12:22:34 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *source, long unsigned int size)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(source));
	while (source[i] && (long unsigned int)(i + dest_len) < size - 1)
	{
		dest[dest_len + i] = source[i];
		i++;
	}
	if ((long)size < 0)
		size = ft_strlen(source) + dest_len;
	if ((int)size < dest_len)
		return (ft_strlen(source) + size);
	dest[dest_len + i] = '\0';
	return (ft_strlen(source) + dest_len);
}
