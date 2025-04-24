/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:04:04 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 11:19:45 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_isascii.c
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;
// 	char	test_chars [] = {'*', '/', '1', 'h', 'R', ' ', '^', 200, 43, '|'};
// 	int		i;
// 	int		num_chars;

// 	num_chars = sizeof(test_chars) / sizeof(test_chars[0]);
// 	// Test ft_isascii
// 	i = 0;
// 	printf("\nTest ft_isascii\n");
// 	while (i < num_chars)
// 	{
// 		c = test_chars[i];
// 		if (ft_isascii(c) == 1)
// 			printf("The chararcter '%c'is ascii.\n", c);
// 		else
// 			printf("The chararcter '%c'is not ascii.\n", c);
// 		i++;
// 	}
// 	// Test isascii
// 	i = 0;
// 	printf("\nTest isascii\n");
// 	while (i < num_chars)
// 	{
// 		c = test_chars[i];
// 		if (isascii(c) != 0)
// 			printf("The chararcter '%c'is ascii.\n", c);
// 		else
// 			printf("The chararcter '%c'is not ascii.\n", c);
// 		i++;
// 	}
// 	return (0);
// }
