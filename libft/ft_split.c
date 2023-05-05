/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:29:16 by douattar          #+#    #+#             */
/*   Updated: 2022/07/31 01:19:39 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	while_separator(char *str, char c)
{
	int	i;

	i = 0;
	while (c == str[i])
		i++;
	return (i);
}

static int	nextsep(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static int	ft_lenchar(char *str, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i += while_separator(str + i, c);
		if (str[i] == '\0')
			break ;
		res++;
		i += nextsep(str + i, c);
	}
	return (res);
}

static char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		length;

	if (!str)
		return ((char **)(NULL));
	res = (char **)malloc(sizeof(char *) * (ft_lenchar((char *)str, c) + 1));
	if (!res)
		return ((char **)(NULL));
	i = 0;
	j = 0;
	while (i < ft_lenchar((char *)str, c))
	{
		j += while_separator((char *)str + j, c);
		length = nextsep((char *)str + j, c);
		res[i] = malloc(sizeof(char) * (length + 1));
		if (!res[i])
			return ((char **)(NULL));
		ft_strncpy(res[i], (char *)str + j, length);
		j += length;
		i++;
	}
	res[i] = 0;
	return (res);
}
