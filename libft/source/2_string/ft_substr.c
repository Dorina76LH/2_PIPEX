/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/12/06 13:18:46 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra 
ft_substr.c ft_strlen.c ft_calloc.c ft_strdup.c
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*extract_str;

	if (s == NULL)
		return (NULL);
	str_len = 0;
	while (s[str_len] != '\0')
		str_len++;
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > str_len)
		len = str_len - start;
	extract_str = malloc(len + 1);
	if (!extract_str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		extract_str[i] = s[start + i];
		i++;
	}
	extract_str[i] = '\0';
	return (extract_str);
}
// int	main(void)
// {
// 	char  *texte = "En mar nem muzsikalok";
// 	char  *resultat;

// 	printf("Texte : %s \n", texte);
// 	// Exemple 1 : Chaine entiere
// 	resultat = ft_substr(texte, 3, 2);
// 	printf("Extrait : %s\n", resultat);
// 	free (resultat);
// 	// Exemple 2 : Chaine valide
// 	resultat = ft_substr(texte, 7, 13);
// 	printf("Extrait : %s\n", resultat);
// 	free (resultat);
// 	// Exemple 3 : Debordement longueur
// 	resultat = ft_substr(texte, 7, 25);
// 	printf("Extrait : %s\n", resultat);
// 	free (resultat);
// 	// Start en dehors de len_total
// 	resultat = ft_substr(texte, 30, 13);
// 	printf("Extrait : %s\n", resultat);
// 	free (resultat);
// 	return (0);
// }