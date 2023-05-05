/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:40:38 by douattar          #+#    #+#             */
/*   Updated: 2022/10/24 13:34:09 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing_error(t_error_type type)
{
	write(2, "Error\n", 6);
	if (type == ARGUMENTS_NUMBER)
		write(2, "Invalid number of arguments\n", 28);
	else if (type == INVALID_EXTENSION)
		write(2, "Extension not valid\n", 20);
	else if (type == EXIST_FILE)
		write(2, "Coudln't open the file\n", 23);
	return (TRUE);
}

static int	in_table(char *first)
{
	int			i;
	const char	direct[6][2] = {"NO", "SO", "WE", "EA", "F", "C"};

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(direct[i], first, 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	fill_variable(t_parsing *res, char *line)
{
	char		**info;
	int			check;
	int			i;

	info = ft_split(line, ' ');
	if (info == NULL)
		return (END_FILL);
	check = CONTINUE_FILL;
	if (strlen_double(info) > 0 && (ft_strlen(line) > 1 && line[0] != '\n'))
	{
		i = in_table(info[0]);
		if (strlen_double(info) != 2 || i == -1)
			check = END_FILL;
		else
		{
			if (info[1][ft_strlen(info[1]) - 1] == '\n')
				info[1][ft_strlen(info[1]) - 1] = '\0';
			if (i < 4)
				check = cardinal_variable(res, info[1], i);
			else if (i < 6)
				check = color_variable(res, info[1], i % 4);
		}
	}
	strfree_double(info);
	return (check);
}

static int	check_struct(t_parsing *res)
{
	if (res->north == NULL || res->south == NULL || \
			res->west == NULL || res->south == NULL)
	{
		write(2, "Error\nVariable missing\n", 23);
		return (0);
	}
	else if (res->sol == -1 || res->plafond == -1)
	{
		write(2, "Error\nVarialbe missing\n", 23);
		return (0);
	}
	return (1);
}

int	extract_info(t_parsing *res, char *filename)
{
	int			check_error;
	int			fd;
	char		*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (parsing_error(EXIST_FILE));
	line = get_next_line(fd);
	check_error = fill_variable(res, line);
	while (line != NULL && check_error == CONTINUE_FILL)
	{
		free(line);
		line = get_next_line(fd);
		check_error = fill_variable(res, line);
	}
	if (check_error != ERROR_FILL && check_struct(res))
		check_error = complete_map(res, fd, line);
	else
	{
		check_error = ERROR_FILL;
		free(line);
	}
	get_next_line(-2);
	close(fd);
	return (check_error == ERROR_FILL || !check_struct(res));
}
