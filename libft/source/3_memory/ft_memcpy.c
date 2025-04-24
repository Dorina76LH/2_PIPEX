/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:51:05 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 11:57:19 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Werror -Wextra -Wall ft_memcpy.c ft_strlen.c
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	if (n == 0 || (dst == NULL && src == NULL))
		return (dst);
	destination = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*destination = *source;
		destination++;
		source++;
		i++;
	}
	return (dst);
}

// int	main (void)
// {
// 	// Test 1 : Tb int
// 	int	src1[5] = {1, 2, 3, 4, 5};
// 	int	dest11[5];
// 	int dest12[5];
// 	memcpy(dest11, src1, 5*sizeof(int));
// 	printf("Tb int copiee avec memcpy : ");
// 	int i = 0;
// 	while (i < 5)
// 		{
// 			printf("%d ", dest11[i]);
// 			i++;
// 		}
// 	printf("\n");
// 	memcpy(dest12, src1, 5*sizeof(int));
// 	printf("Tb int copiee avec ft_memcpy : ");
// 	i = 0;
// 	while (i < 5)
// 		{
// 			printf("%d ", dest12[i]);
// 			i++;
// 		}
// 	printf("\n");
// 	// Test 2 : Chaine de car
// 	char	src2[] = "Balnak ki a partra !";
// 	char	dest21[100];
// 	char	dest22[100];
// 	memcpy(dest21, src2, (ft_strlen(src2) + 1));
// 	printf("Chaine copiee avec memcpy : %s \n", dest21);
// 	ft_memcpy(dest22, src2, (ft_strlen(src2) + 1));
// 	printf("Chaine copiee avec ft_memcpy : %s \n", dest21);
// 	return (0);
// }