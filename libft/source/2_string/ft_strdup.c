/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:42:48 by doberes           #+#    #+#             */
/*   Updated: 2024/12/06 13:31:13 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Werror ft_strdup.c ft_strlen.c
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	dest = (char *)malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	const char	*source = "Repulogepek oceanok a fuvek a fak a mezok a viragok";
// 	char		*copy1 = strdup(source);
// 	char		*copy2 = ft_strdup(source); 
// 	printf("Source : %s\n", source);
// 	if (copy1 != NULL)
// 	{
// 		printf("Destination strdup    : %s\n", copy1);
// 		free(copy1);
// 	}
// 	if (copy2 != NULL)
// 	{
// 		printf("Destination ft_strdup : %s\n", copy2);
// 		free(copy2);
// 	}
// 	else
// 		printf("Erreur d'allocation de memoire.\n");
// 	return (0);
// }