/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:08:40 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 13:20:04 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_toupper.c
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

// int	main(void)
// {
// 	// Declaring variables
// 	char	c_original;
// 	char	c_converted;
// 	char	test_chars[] = {'H', 'i', ' ', '4', '2', '!', '@'};
// 	int		i;
// 	int		num_chars;

// 	// Set variables
// 	num_chars = sizeof(test_chars) / sizeof(test_chars [0]);

// 	// Test ft_toupper
// 	printf("\nTest fonction ft_toupper\n");
// 	i = 0;
// 	while (i < num_chars)
// 	{
// 		c_original = test_chars [i];
// 		c_converted = ft_toupper(c_original);
// 		printf("Original : '%c' | Converted : '%c'\n", c_original, c_converted);
// 		i++;
// 	}

// 	// Test toupper
// 	printf("\nTest fonction toupper\n");
// 	i = 0;
// 	while (i < num_chars)
// 	{
// 		c_original = test_chars [i];
// 		c_converted = toupper(c_original);
// 		printf("Original : '%c' | Converted : '%c'\n", c_original, c_converted);
// 		i++;
// 	}
// 	return (0);
// }
