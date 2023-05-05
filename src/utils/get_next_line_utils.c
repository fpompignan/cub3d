/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:28:14 by douattar          #+#    #+#             */
/*   Updated: 2022/10/11 14:50:11 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*error_return(char **rest)
{
	free(*rest);
	*rest = NULL;
	return (NULL);
}

int	cat(char *dest, char *source, long unsigned int size)
{
	int	i;
	int	dest_len;

	i = 0;
	dest[0] = '\0';
	dest_len = ft_strlen(dest);
	if (source == NULL)
		return (0);
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
	free(source);
	return (dest_len);
}
