/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:41:33 by douattar          #+#    #+#             */
/*   Updated: 2021/12/04 11:50:42 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, long unsigned int len)
{
	char	*res;
	int		i;
	int		length;

	i = 0;
	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	while ((long unsigned int)i < len && s[start + i] != '\0')
		i++;
	length = i;
	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
