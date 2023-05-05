/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:24:37 by douattar          #+#    #+#             */
/*   Updated: 2022/10/13 13:41:12 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_chr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == (char)(c))
			return (i);
	if (s[i] == c)
		return (i);
	return (-1);
}

static char	*ft_join(char **s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;		

	if (!(*s1) && !s2)
		return ((char *)(NULL));
	res = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	i = 0;
	while ((*s1)[i])
	{
		res[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(*s1);
	*s1 = res;
	return (res);
}

static char	*ft_sub(char const *s, unsigned int start, long unsigned int len)
{
	char	*res;
	int		i;
	int		length;

	i = 0;
	if (!s || start > (unsigned int)ft_strlen(s) || start == len)
		return (NULL);
	while ((long unsigned int)i < len && s[start + i] != '\0')
		i++;
	length = i;
	if (i == 0)
		return (NULL);
	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	c(char **pointer, int next)
{
	int	i;

	if (next == 1)
		free(*pointer);
	*pointer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*pointer == NULL)
		return (1);
	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		(*pointer)[i] = 0;
		i++;
	}
	return (*pointer == NULL);
}

char	*get_next_line(int fd)
{
	char			*res;
	char			*temp;
	static char		*rest = NULL;

	if (fd < 0 || c(&res, 2) || c(&temp, 2) || cat(res, rest, BUFFER_SIZE) < 0)
		return (error_return(&rest));
	while (ft_chr(res, '\n') == -1 && read(fd, temp, BUFFER_SIZE) > 0)
	{
		if (ft_join(&res, temp) == NULL)
			return (NULL);
		c(&temp, 1);
	}
	free(temp);
	rest = NULL;
	if (res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	if (ft_chr(res, '\n') == -1)
		return (res);
	rest = ft_sub(res, ft_chr(res, '\n') + 1, ft_strlen(res));
	temp = ft_sub(res, 0, ft_chr(res, '\n') + 1);
	free(res);
	return (temp);
}
