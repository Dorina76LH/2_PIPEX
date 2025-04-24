/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:29:04 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 16:05:38 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_memchr.c
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
// int main(void)
// {
// 	char str[] = "Hello, world!";
// 	printf("Chaine : %s\n", str);
// 	char *result = memchr(str, 'w', strlen(str));
// 	if (!result)
// 		printf("Memchr : 'w' trouvee a la position %ld.\n", result - str);
// 	else
// 		printf("Memchr : 'w' non trouvee.\n");
// 	char *result2 = ft_memchr(str, 'w', strlen(str));
// 	if (!result)
// 		printf("Ft_memchr : 'w' trouvee a la position %ld.\n", result2 - str);
// 	else
// 		printf("Ft_memchr : 'w' non trouvee.\n");
// 	result = memchr(str, 'z', strlen(str));
// 	if (!result)
// 		printf("Memchr : 'z' trouvee a la position %ld.\n", result - str);
// 	else
// 		printf("Memchr : 'z' non trouvee.\n");
// 	result2 = ft_memchr(str, 'z', strlen(str));
// 	if (!result)
// 		printf("Ft_memchr : 'z' trouvee a la position %ld.\n", result2 - str);
// 	else
// 		printf("Ft_memchr : 'z' non trouvee.\n");
// 	return (0);
// }