/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:02:59 by douattar          #+#    #+#             */
/*   Updated: 2022/10/20 14:29:28 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_struct(t_parsing *res)
{
	if (res == NULL)
		return ;
	res->north = NULL;
	res->south = NULL;
	res->west = NULL;
	res->east = NULL;
	res->sol = -1;
	res->plafond = -1;
	res->width = 0;
	res->length = 0;
	res->map = NULL;
}

void	free_struct(t_parsing *res)
{
	if (res == NULL)
		return ;
	free(res->north);
	res->north = NULL;
	free(res->south);
	res->south = NULL;
	free(res->west);
	res->west = NULL;
	free(res->east);
	res->east = NULL;
	if (res->map != NULL)
		strfree_double(res->map);
	res->map = NULL;
	free(res);
}

int	check_struct_default(t_parsing *res)
{
	if (res == NULL || res->map == NULL)
		return (1);
	if (!res->north || !res->south || !res->west || !res->west)
		return (1);
	if (res->sol < 0 || res->plafond < 0 || res->width <= 0 || res->length <= 0)
		return (1);
	return (0);
}
