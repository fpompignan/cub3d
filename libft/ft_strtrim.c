/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:30:59 by douattar          #+#    #+#             */
/*   Updated: 2021/12/04 12:08:18 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	still_in(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != c && set[i] != '\0')
		i++;
	return (set[i] == c);
}

static int	not_finish(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (still_in(s1[i], set) && s1[i] != '\0')
		i++;
	return (s1[i] != '\0');
}

static	char	ft_length(char const *s1, char const *set)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (still_in(s1[i], (char *)set) && s1[i] != '\0')
		i++;
	while (not_finish((char *)(s1 + i), (char *)set) && s1[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !set)
		return ((char *)(0));
	res = malloc(sizeof(char) * (ft_length((char *)s1, (char *)set) + 1));
	i = 0;
	j = 0;
	if (!res)
		return (0);
	while (still_in(s1[i], (char *)set) && s1[i] != '\0')
		i++;
	while (not_finish((char *)(s1 + i), (char *)set) && s1[i] != '\0')
	{
		res[j] = s1[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
