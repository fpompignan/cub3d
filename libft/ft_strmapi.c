/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:19:07 by douattar          #+#    #+#             */
/*   Updated: 2021/12/04 12:00:42 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (ft_strlen((char *)(s)) + 1));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = f((unsigned int)i, (char)s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
