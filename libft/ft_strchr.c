/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:36:57 by douattar          #+#    #+#             */
/*   Updated: 2021/11/29 14:12:04 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == (char)(c))
			return ((char *)(s + i));
	if (s[i] == c)
		return ((char *)(s + i));
	return ((char *)('\0'));
}