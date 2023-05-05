/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:10:04 by douattar          #+#    #+#             */
/*   Updated: 2021/12/03 17:01:17 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return ((char *)(0));
	i = 0;
	while (s[i])
	{
		res[i] = (char)(s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
