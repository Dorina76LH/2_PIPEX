/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:14:20 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 12:00:29 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Werror -Wextra -Wall ft_memcpy.c ft_memmove.c
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	if (dst == src || len == 0)
		return (dst);
	destination = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (!destination && !source)
		return (NULL);
	if (destination > source && destination < (source + len))
	{
		i = len;
		while (i > 0)
		{
			i--;
			destination[i] = source[i];
		}
	}
	else
		ft_memcpy(destination, source, len);
	return (dst);
}

// int	main(void)
// {
// 	char buffer[50] = "Nem vagyok en reszeg, csak hat igen igen kaba!";
// 	char buffer2[50] = "Nem vagyok en reszeg, csak hat igen igen kaba!";

// 	printf("Avant memmove                      : %s\n", buffer);

// 	//Deplacement avec chevauchement
// 	memmove(buffer + 7, buffer, 5);
// 	printf("Apres memmove (chevauchement)      : %s\n", buffer);
// 	ft_memmove(buffer2 + 7, buffer, 5);
// 	printf("Apres ft_memmove (chevauchement)   : %s\n", buffer);

// 	// Deplacement sans chevauchement
// 	char src[] = "Test";
// 	memmove(buffer, src, 4);
// 	printf("Apres memmove (sans chevauchement) : %s\n", buffer);
// 	ft_memmove(buffer2, src, 4);
// 	printf("Apres ft_memmove (chevauchement)   : %s\n", buffer);

// 	return (0);
// }