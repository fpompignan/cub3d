/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:55:09 by douattar          #+#    #+#             */
/*   Updated: 2021/12/03 16:57:08 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;

	res = malloc(nmemb * size);
	if (!res)
		return ((void *)(0));
	i = 0;
	while (i < size * nmemb)
	{
		res[i] = 0;
		i++;
	}
	return ((void *)(res));
}
