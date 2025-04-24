/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/12/06 13:32:40 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_strrchr.c ft_strlen.c
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	to_find;
	int				i;

	i = 0;
	while (s[i] != '\0')
		i++;
	to_find = (unsigned char)(c & 0xFF);
	while (i >= 0)
	{
		if ((unsigned char) s[i] == to_find)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	*string = "teste"; // Balnak ki a partra !
// 	char		c1 = 'e';
// 	char		c2 = 'y';
// 	char		c3 = 'c';

// 	char	*result1 = strrchr(string, c1);
// 	if (result1 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c1, string, result1 - string);
// 	else
// 		printf("\n '%c' n'a pas trouve dans la chaine '%s'\n", c1, string);
// 	char	*result2 = ft_strrchr(string, c1);
// 	if (result2 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c1, string, result2 - string);
// 	else
// 		printf("\n '%c' n'a pas trouve dans la chaine '%s'\n", c1, string);
// 	char	*result3 = strrchr(string, c2);
// 	if (result3 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c2, string, result3 - string);
// 	else
// 		printf("\n '%c' n'a pas trouve dans la chaine '%s'\n", c2, string);
// 	char 	*result4 = ft_strrchr(string, c2);
// 	if (result4 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c2, string, result4 - string);
// 	else
// 		printf("\n '%c' n'a pas trouve dans la chaine '%s'\n", c2, string);
// 	char	*result5 = strrchr(string, c3);
// 	if (result5 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c3, string, result5 - string);
// 	else
// 		printf("\n '%c' n'a pas trouve dans la chaine '%s'\n", c3, string);
// 	char 	*result6 = ft_strrchr(string, c3);
// 	if (result6 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c3, string, result6 - string);
// 	else
// 		printf("\n '%c' n'a pas trouve dans la chaine '%s'\n", c3, string);
// 	return (0);
// }