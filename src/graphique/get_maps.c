/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:45:34 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/19 15:58:13 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init_maps(t_board *board)
{
	int	i;
	int	j;

	board->maps = malloc(sizeof(int *) * board->height);
	if (!board->maps)
		exit_wolf(board);
	i = 0;
	while (i < board->height)
	{
		board->maps[i] = malloc(sizeof(int) * board->width);
		if (!board->maps[i])
			exit_wolf(board);
		i++;
	}
	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			board->maps[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	get_mapss(t_board *board, t_parsing *info)
{
	int	i;
	int	j;

	init_maps(board);
	i = 0;
	while (info->map[i] != NULL)
	{
		j = 0;
		while (info->map[i][j] != 0)
		{
			if (info->map[i][j] == '0')
				board->maps[i][j] = 0;
			else if (info->map[i][j] == 'N')
				board->maps[i][j] = 2;
			else if (info->map[i][j] == 'S')
				board->maps[i][j] = 4;
			else if (info->map[i][j] == 'W')
				board->maps[i][j] = 5;
			else if (info->map[i][j] == 'E')
				board->maps[i][j] = 3;
			j++;
		}
		i++;
	}
}

void	copy_map(t_board *board, t_parsing *info)
{
	unsigned int	i;

	board->map = malloc(sizeof(char *) * (info->length + 1));
	if (!board->map)
		exit_wolf(board);
	i = 0;
	while (i < info->length)
	{
		board->map[i] = ft_strdup(info->map[i]);
		if (!board->map[i])
			exit_wolf(board);
		i++;
	}
	board->map[info->length] = NULL;
}

void	copy_texture_cardinal(t_board *board, t_parsing *info)
{
	board->no = ft_strdup(info->north);
	board->so = ft_strdup(info->south);
	board->ea = ft_strdup(info->east);
	board->we = ft_strdup(info->west);
	if (!board->no || !board->so || !board->ea || !board->we)
		exit_wolf(board);
}
