/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 15:12:34 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_strjoin.c ft_strlen.c
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i_str1;
	int		i_str2;
	int		len_str1;
	int		len_str2;
	char	*result;

	len_str1 = ft_strlen(s1);
	len_str2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_str1 + len_str2 +1));
	if (result == NULL)
		return (NULL);
	i_str1 = 0;
	while (i_str1 < len_str1)
	{
		result[i_str1] = s1[i_str1];
		i_str1++;
	}
	i_str2 = 0;
	while (i_str2 < len_str2)
	{
		result[i_str1 + i_str2] = s2[i_str2];
		i_str2++;
	}
	result[i_str1 + i_str2] = '\0';
	return (result);
}

// int	main(void)
// {
// 	// Declaration des variables
// 	const char	*str1 = "En mar nem muzsikalok, csak egy jelet adok a gepnek:";
// 	const char	*str2 = "o mutassa meg helyettem amikor mozdul bennem a lelek";
// 	char		*result;

// 	// Imprimer str1 et str2
// 	printf("String 1 : %s\n", str1);
// 	printf("String 2 : %s\n", str2);

// 	// Appel ft_strjoin
// 	result = ft_strjoin(str1, str2);

// 	// Verifier la concatenation
// 	if (result != NULL)
// 	{
// 		printf("Resultat : %s\n", ft_strjoin(str1, str2));
// 		free(result);
// 	}
// 	else
// 		printf("Erreur d'allocation de la memoire\n");

// 	return (0);
// }
