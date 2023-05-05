/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:45:42 by douattar          #+#    #+#             */
/*   Updated: 2022/10/24 13:24:45 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_file_extension(int argc, char **argv)
{
	int			i;
	int			j;
	int			length;
	const char	extension[] = ".cub";

	if (argc != 2)
		return (parsing_error(ARGUMENTS_NUMBER));
	length = ft_strlen(argv[1]);
	i = length - 4;
	if (i < 4)
		return (parsing_error(INVALID_EXTENSION));
	j = 0;
	while (extension[j] == argv[1][i + j] && i + j < length)
		j++;
	if (j != 4)
		return (parsing_error(INVALID_EXTENSION));
	return (j != 4);
}

t_parsing	*parse(int argc, char **argv)
{
	t_parsing	*res;

	if (check_file_extension(argc, argv))
		return (NULL);
	res = malloc(sizeof(t_parsing));
	if (res == NULL)
		return (NULL);
	init_struct(res);
	if (extract_info(res, argv[1]) || check_struct_default(res))
	{
		free_struct(res);
		return (NULL);
	}
	return (res);
}
