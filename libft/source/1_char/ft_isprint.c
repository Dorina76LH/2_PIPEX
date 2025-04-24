/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:44:01 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 11:12:40 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_isprint.c
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;
// 	char	test_chars[] = {'\n', '\t', '\0', 127, '5', '%', '+', 'a', 'Z'};
// 	int		i;
// 	int		num_chars;

// 	num_chars = sizeof(test_chars) / sizeof(test_chars[0]);
// 	// Test ft_isprint
// 	i = 0;
// 	printf("\nTest ft_isprint\n");
// 	while (i < num_chars)
// 	{
// 		c = test_chars[i];
// 		if (ft_isprint(c) == 1)
// 			printf("The char '%c' is printable\n", c);
// 		else
// 			printf("The char '%c' is not printable\n", c);
// 		i++;
// 	}
// 	// Test isprint
// 	i = 0;
// 	printf("\nTest ft_isprint\n");
// 	while (i < num_chars)
// 	{
// 		c = test_chars[i];
// 		if (isprint(c) != 0)
// 		{
// 			printf("The char '%c' is printable\n", c);
// 			//printf("The value returned by isprint is : %d\n", isprint(c));
// 		}
// 		else
// 		{
// 			printf("The char '%c' is not printable\n", c);
// 			//printf("The value returned by isprint is : %d\n", isprint(c));
// 		}
// 		i++;
// 	}
// 	return (0);
// }
