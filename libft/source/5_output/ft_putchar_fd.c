/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 13:13:05 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Wextra -Werror ft_putchar_fd.c
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	int		file_descriptor;
// 	char	character;

// 	file_descriptor = 1;
// 	character = 'Z';
// 	ft_putchar_fd(character, file_descriptor);
// 	return (0);
// }
