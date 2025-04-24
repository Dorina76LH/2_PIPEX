/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:05:06 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 12:02:19 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_memset.c
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	data[5] = {'1', '2', '3', '4', '5'};
// 	int		i;
// 	int		n;

// 	printf("\nAvant memset\n");
// 	i = 0;
// 	n = 5;
// 	while (i < n)
// 	{
// 		printf("%c", data[i]);
// 		i++;
// 	}
// 	printf("\nApres memset\n");
// 	ft_memset(data, '0', n);
// 	i = 0;
// 	n = 5;
// 	while (i < n)
// 	{
// 		printf("%c", data[i]);
// 		i++;
// 	}
// 	return (0);
// }
