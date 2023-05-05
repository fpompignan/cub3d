/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdouble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:36:28 by douattar          #+#    #+#             */
/*   Updated: 2022/10/07 15:37:07 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**strcpy_double(char **str)
{
	int		i;
	int		length;
	char	**res;

	length = strlen_double(str);
	i = 0;
	res = malloc(sizeof(char **) * length);
	while (str[i] != NULL)
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	strfree_double(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	strlen_double(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
