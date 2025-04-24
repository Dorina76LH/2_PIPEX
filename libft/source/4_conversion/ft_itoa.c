/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 16:03:48 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra
ft_itoa.c ft_strlen.c ft_strdup.c ft_calloc.c ft_bzero.c
*/

#include "libft.h"

static int	num_length(long num)
{
	int	count;

	count = 1;
	if (num < 0)
	{
		count++;
		num = num * -1;
	}
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int		len;
	int		position;
	char	*result;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr == 0)
		return (ft_strdup("0"));
	len = num_length(nbr);
	result = (char *)ft_calloc((len + 1), sizeof(char));
	if (!result)
		return (NULL);
	position = len - 1;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0 && position >= 0)
	{
		result[position] = (nbr % 10) + '0';
		nbr = nbr / 10;
		position--;
	}
	return (result);
}

// int	main(void)
// {
// 	int numbers[] = {-1234};
// 	int n = sizeof(numbers) / sizeof(numbers[0]);
// 	int i = 0;

// 	while (i < n)
// 	{
// 		char *str = ft_itoa(numbers[i]);
// 		if (str != NULL)
// 		{
// 			printf("Itoa (%d) = %s\n", numbers[i], str);
// 			free(str);
// 		}
// 		else
// 			printf("Erreur d'allocation de la memoire pour %d\n", numbers[i]);
// 		i++;
// 	}
// 	return (0);
// }
