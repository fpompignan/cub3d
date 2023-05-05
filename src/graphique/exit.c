/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:25:40 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/19 15:59:33 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_tab(int **tab, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(tab[i++]);
	free(tab);
}

void	exit_wolf(t_board *board)
{
	if (board->no)
		free(board->no);
	if (board->so)
		free(board->so);
	if (board->we)
		free(board->we);
	if (board->ea)
		free(board->ea);
	if (board->map)
		free_array(board->map);
	if (board->maps)
		free_tab(board->maps, board->height);
	exit(0);
}
