/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 15:53:38 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
cc -Wall -Werror -Wextra ft_strmapi.c ft_strlen.c 
*/

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*result;

	len = 0;
	while (str[len])
		len++;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	uppercase(unsigned int i, char c)
// {
// 	(void)i;

// 	while (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int	main(void)
// {
// 	const char	*origin = "42 : hello world !";
// 	char		*result = ft_strmapi(origin, uppercase);
// 	if (!result)
// 		return (0);
// 	printf("Chaine origine : %s\n", origin);
// 	printf("Resultat       : %s\n", result);
// 	return (0);
// }
