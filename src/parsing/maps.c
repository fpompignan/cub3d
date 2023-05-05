/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:18:47 by douattar          #+#    #+#             */
/*   Updated: 2022/10/24 13:30:45 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_line_map(char *line)
{
	static int	player = 0;
	int			i;

	i = 0;
	if (line == NULL)
		return (player);
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == 'N' || line[i] == 'S' \
				|| line[i] == 'E' || line[i] == 'W')
			player++;
		else if (line[i] != '0' && line[i] != '1' && line[i] != ' ')
		{
			write(2, "Error\nNot a valid line\n", 23);
			return (1);
		}
		i++;
	}
	line[i] = '\0';
	if (player > 1)
		write(2, "Error\nInvalid number of player\n", 31);
	return (player > 1);
}

static void	list_to_table(t_parsing *res, t_map *first)
{
	int	i;

	res->map = (char **)malloc(sizeof(char *) * (res->length + 1));
	if (res->map == NULL)
		return ;
	i = 0;
	while (first != NULL)
	{
		res->map[i] = ft_strdup(first->line);
		if (res->map[i] == NULL)
			strfree_double(res->map);
		first = first->next;
		i++;
	}
	res->map[i] = NULL;
}

void	get_maps(t_parsing *res, int fd, char *line)
{
	t_map	*first;

	if (line == NULL || check_line_map(line))
		return ;
	first = ft_lstnew(line);
	res->width = ft_strlen(line);
	line = get_next_line(fd);
	res->length = 1;
	while (line != NULL && !check_line_map(line))
	{
		ft_lstadd_back(&first, ft_lstnew(line));
		res->length++;
		if ((unsigned int)ft_strlen(line) > res->width)
			res->width = ft_strlen(line);
		line = get_next_line(fd);
	}
	free(line);
	if (line == NULL && check_line_map(NULL) == 1)
		list_to_table(res, first);
	else if (line == NULL)
		write(2, "Error\nInvalid number of player\n", 31);
	ft_lstclear(first);
}

static int	check_map(const t_parsing *res)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < res->length)
	{
		j = 0;
		while (res->map[i][j] != '\0')
		{
			if (little_check(res, i, j))
			{
				write(2, "Error\nMap not closed\n", 21);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	complete_map(t_parsing *res, int fd, char *first)
{
	if (first == NULL)
		return (ERROR_FILL);
	get_maps(res, fd, first);
	if (res->map == NULL)
		return (ERROR_FILL);
	if (check_map(res))
	{
		strfree_double(res->map);
		res->map = NULL;
		return (ERROR_FILL);
	}
	return (END_FILL);
}
