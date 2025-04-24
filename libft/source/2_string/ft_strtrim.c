/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 15:58:31 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_strtrim.c ft_strdup.c ft_strlen.c ft_strchr.c
ft_strrchr.c ft_substr.c ft_calloc.c ft_bzero.c
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set || s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1 ;
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++;
	while (end > start && ft_strrchr(set, (int)s1[end]))
		end--;
	if (end < start)
		return (ft_strdup(""));
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}
// int main(void) 
// {
//     // Cas de test avec des chaînes différentes et des caractères à supp
//     const char *tests[] =
// 	{
//         "   Hello, World!   ",      // Espaces au début et à la fin
//         "xxHello, World!xx",        // 'x' au début et à la fin
//         "***Hello, World!***",      // '*' au début et à la fin
//         "++++Hello, World!++++",    // '+' au début et à la fin
//         "Hello, World!",            // Aucun caractère de trim
//         "       ",                  // Uniquement des espaces
//         "*****",                    // Uniquement des caractères dans set
//         "",                         // Chaîne vide
//         NULL                        // Cas de chaîne NULL
//     };
//     const char *set = " *+x"; // Caractères à retirer ( ,*,+,x)

//     // Initialiser l'index pour la boucle while
//     int i = 0;

//     // Boucle while pour tester chaque chaîne dans tests
//     while (tests[i] != NULL)
// 	{
//         const char *s1 = tests[i];
//         printf("Original: \"%s\"\n", s1);

//         // Appel de ft_strtrim
//         char *trimmed = ft_strtrim(s1, set);
//         if (trimmed != NULL) {
//             printf("Trimmed : \"%s\"\n\n", trimmed);
//             free(trimmed); // Libérer la mémoire allouée
//         } else {
//             printf("Erreur ou chaîne NULL.\n\n");
//         }

//         // Passer au cas de test suivant
//         i++;
//     }
//     return 0;
// }