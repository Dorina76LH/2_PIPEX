/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:05:06 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 11:19:45 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_bzero.c
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char	data[50] = "Talk to me softly. There is something in your eyes";
// 	int		i;
// 	int		n;

// 	printf("\nAvant bzero\n");
// 	i = 0;
// 	n = 50;
// 	while (i < n)
// 	{
// 		printf("%c", data[i]);
// 		i++;
// 	}
// 	printf("\nApres bzero\n");
// 	ft_bzero(data, n);
// 	i = 0;
// 	n = 50;
// 	while (i < n)
// 	{
// 		printf("%c", data[i]);
// 		i++;
// 	}
// 	return (0);
// }
