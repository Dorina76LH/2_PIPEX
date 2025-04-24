/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 14:56:56 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_strchr.c
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	unsig_char;

	unsig_char = (unsigned char)c;
	while (*s != '\0' && unsig_char != *s)
		s++;
	if (*s == unsig_char)
		return ((char *)s);
	return (0);
}

// int	main(void)
// {
// 	const char	*string = "Balnak ki a partra !";
// 	char		c1 = 'a';
// 	char		c2 = 'k';
// 	char		c3 = 'z';

// 	char	*result1 = strchr(string, c1);
// 	if (result1 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c1, string, result1 - string);
// 	else
// 		printf("\n '%c' n'a pas ete trouvee dans la chaine '%s'\n", c1, string);

// 	char	*result2 = ft_strchr(string, c1);
// 	if (result2 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c1, string, result2 - string);
// 	else
// 		printf("\n '%c' n'a pas ete trouvee dans la chaine '%s'\n", c1, string);

// 	char	*result3 = strchr(string, c2);
// 	if (result3 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c2, string, result3 - string);
// 	else
// 		printf("\n '%c' n'a pas ete trouvee dans la chaine '%s'\n", c2, string);

// 	char 	*result4 = ft_strchr(string, c2);
// 	if (result4 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c2, string, result4 - string);
// 	else
// 		printf("\n '%c' n'a pas ete trouvee dans la chaine '%s'\n", c2, string);

// 	char 	*result5 = strchr(string, c3);
// 	if (result5 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c3, string, result5 - string);
// 	else
// 		printf("\n '%c' n'a pas ete trouvee dans la chaine '%s'\n", c3, string);

// 	char 	*result6 = ft_strchr(string, c3);
// 	if (result6 != NULL)
// 		printf("\n'%c' dans '%s' | pos : %ld\n", c3, string, result6 - string);
// 	else
// 		printf("\n '%c' n'a pas ete trouvee dans la chaine '%s'\n", c3, string);
// 	return (0);
// }