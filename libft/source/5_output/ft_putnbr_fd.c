/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 15:55:40 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Wextra -Werror ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

// int	main(void)
// {
// 	int	number;
// 	int	file_descriptor;

// 	file_descriptor = 1;
// 	number = -2147483648;
// 	ft_putnbr_fd(number, file_descriptor);
// 	write (file_descriptor, "\n", 1);
// 	number = -7000;
// 	ft_putnbr_fd(number, file_descriptor);
// 	write (file_descriptor, "\n", 1);
// 	number = 42;
// 	ft_putnbr_fd(number, file_descriptor);
// 	write (file_descriptor, "\n", 1);
// 	number = 2147483647;
// 	ft_putnbr_fd(number, file_descriptor);
// 	write (file_descriptor, "\n", 1);
// 	return (0);
// }
