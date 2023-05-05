/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:15:46 by douattar          #+#    #+#             */
/*   Updated: 2021/12/03 18:47:00 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_display(long int n, int fd)
{
	char	letter[1];

	if (n == 0)
		(void)n;
	else
	{
		recursive_display(n / 10, fd);
		letter[0] = n % 10 + '0';
		write(fd, letter, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	number;

	number = (long int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	recursive_display(number, fd);
	if (n == 0)
		write(fd, "0", 1);
}
