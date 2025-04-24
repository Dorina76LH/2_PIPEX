/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:57:44 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 11:54:39 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_memcmp.c
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char data1[] = { 'a', 'b', 'c', 'd' };
// 	char data2[] = { 'a', 'b', 'c', 'd' };
// 	int result1 = memcmp(data1, data2, 4);
// 	int result2 = ft_memcmp(data1, data2, 4);

// 	if (result1 == 0)
// 		printf("Retour memcmp : Les blocs sont identiques.\n");
// 	else if (result1 > 0)
// 		printf("Retour memcmp : Le bloc 1 est supérieur au bloc 2.\n");
// 	else
// 		printf("Retour memcmp : Le bloc 1 est inférieur au bloc 2.\n");

// 	if (result2 == 0)
// 		printf("Retour ft_memcmp : Les blocs sont identiques.\n");
// 	else if (result2 > 0)
// 		printf("Retour ft_memcmp : Le bloc 1 est supérieur au bloc 2.\n");
// 	else
// 		printf("Retour ft_memcmp : Le bloc 1 est inférieur au bloc 2.\n");
// 	return (0);
// }