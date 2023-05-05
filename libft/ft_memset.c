/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:45:55 by douattar          #+#    #+#             */
/*   Updated: 2021/12/03 15:53:01 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*dest, int ch, int count)
{
	int		i;
	char	*cast;

	cast = (char *)dest;
	i = 0;
	while (i < count)
		cast[i++] = ch;
	return (cast);
}
