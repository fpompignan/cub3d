/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:57:17 by douattar          #+#    #+#             */
/*   Updated: 2022/10/24 14:26:05 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	cardinal_variable(t_parsing *res, char *file, int i)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		perror(file);
		return (ERROR_FILL);
	}
	close(fd);
	if (i == 0 && res->north == NULL)
		res->north = ft_strdup(file);
	else if (i == 1 && res->south == NULL)
		res->south = ft_strdup(file);
	else if (i == 2 && res->west == NULL)
		res->west = ft_strdup(file);
	else if (i == 3 && res->east == NULL)
		res->east = ft_strdup(file);
	else
	{
		write(2, "Error\nMultiple variable for files\n", 34);
		return (ERROR_FILL);
	}
	return (CONTINUE_FILL);
}

static int	little_atoi(char *color)
{
	const char	max_unsigned[3] = "255";
	int			length;
	int			i;

	length = ft_strlen(color);
	if (length > 3)
	{
		write(2, "Error\nNumber not valid\n", 24);
		return (-1);
	}
	if (length == 3)
	{
		i = 0;
		while (i < 3 && color[i] == max_unsigned[i])
			i++;
		if (color[i] > max_unsigned[i] || !ft_isdigit(color[i]))
		{
			write(2, "Error\nNumber not valid\n", 24);
			return (-1);
		}
	}
	return (ft_atoi(color));
}

static int	check_parsing(t_parsing *res, int i)
{
	int	s;

	if (i)
	{
		s = (res->plafond != -1);
		res->plafond = 0;
	}
	else
	{
		s = (res->sol != -1);
		res->sol = 0;
	}
	return (s);
}

int	color_variable(t_parsing *res, char *file, int i)
{
	char	**color;
	int		nb;
	int		j;

	color = ft_split(file, ',');
	if (color == NULL || strlen_double(color) != 3 || check_parsing(res, i))
	{
		write(2, "Error\nInvalid color\n", 20);
		strfree_double(color);
		return (ERROR_FILL);
	}
	j = 0;
	while (j < 3)
	{
		nb = little_atoi(color[j]);
		if (nb == -1)
			break ;
		if (i)
			res->plafond += pow(256, 2 - j) * (unsigned char)(nb);
		else
			res->sol += pow(256, 2 - j) * (unsigned char)(nb);
		j++;
	}
	strfree_double(color);
	return ((j < 3) + 1);
}

// Check if the map is closed
int	little_check(const t_parsing *res, unsigned int i, unsigned int j)
{
	if (res->map[i][j] == 'N' || res->map[i][j] == 'S' || \
			res->map[i][j] == 'E' || res->map[i][j] == 'W' || \
			res->map[i][j] == '0')
	{
		if (i == 0 || i == (res->length - 1) || j == 0 \
				|| j == (unsigned int)(ft_strlen(res->map[i]) - 1))
			return (1);
		if (ft_strchr("NSEW01", res->map[i][j - 1]) == NULL \
				|| ft_strchr("NSEW01", res->map[i][j + 1]) == NULL)
			return (1);
		if ((unsigned int)(ft_strlen(res->map[i - 1])) <= j \
				|| ft_strchr("NSEW01", res->map[i - 1][j]) == NULL)
			return (1);
		if ((unsigned int)(ft_strlen(res->map[i + 1])) <= j \
				|| ft_strchr("NSEW01", res->map[i + 1][j]) == NULL)
			return (1);
	}
	return (0);
}
