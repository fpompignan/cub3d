/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:24:53 by douattar          #+#    #+#             */
/*   Updated: 2021/12/02 12:18:54 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len == -1)
		len = ft_strlen(big);
	if (*little == '\0')
		return ((char *)(big));
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && j < ft_strlen(little))
			j++;
		if (little[j] == '\0' && i + j <= len)
			return ((char *)(big + i));
		i++;
	}
	return ((char *)(0));
}
