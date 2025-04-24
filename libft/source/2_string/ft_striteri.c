/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 16:01:02 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_striteri.c ft_strlen.c ft_strdup.c
*/

#include "libft.h"

// int	ft_toupper(int c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		c = c - 32;
// 	return (c);
// }

// static void	getallupper(unsigned int i, char *str)
// {
// 	(void)i;
// 	str[0] = ft_toupper(str[0]);
// }

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
	return ;
}

//  int	main(void)
//  {
//  	char	string1[] = "tankcsapda";
// 	char	*string2 = ft_strdup(string1);

//  	printf("Avant : %s\n", string2);
//  	ft_striteri(string2, getallupper);
//  	printf("Apres : %s\n", string2);
//  	return (0);
//  }
