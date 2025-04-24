/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/12/06 13:23:46 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_strlcpy.c ft_strlen.c -lbsd
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (src == NULL || dst == NULL)
		return (0);
	if (size != 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (size -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// int	main(void)
// {
// 	char			source[] = "I was made for lovin' you";
// 	char			destination1[26];
// 	char			destination2[20];
// 	char			destination3[0];
// 	unsigned int	len_source;

// 	len_source = ft_strlen(source);
// 	printf("\nSource : %s | Len : %u\n", source, len_source);
// 	//Cas 1 : Taille suiffisante
// 	ft_strlcpy(destination1, source, 26);
// 	printf("\nDestination1 : %s\n", destination1);
// 	strlcpy(destination1, source, 26);
// 	printf("\nDestination1 : %s\n", destination1);
// 	//Cas 2 : Taille insuffisante
// 	ft_strlcpy(destination2, source, 20);
// 	printf("\nDestination2 : %s\n", destination2);
// 	strlcpy(destination2, source, 20);
// 	printf("\nDestination2 : %s\n", destination2);
// 	//Cas 3 : Taille null
// 	ft_strlcpy(destination3, source, 0);
// 	printf("\nDestination3 : %s\n", destination3);
// 	strlcpy(destination3, source, 0);
// 	printf("\nDestination3 : %s\n", destination3);
// 	return (0);
// }
