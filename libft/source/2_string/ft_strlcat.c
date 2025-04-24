/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/12/06 13:34:07 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Wextra -Werror ft_strlcat.c ft_strlen.c -lbsd
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i_src;
	size_t	i_dst;

	if (src == NULL && dst == NULL)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_size == 0 || dst_size <= dst_len)
		return (dst_size + src_len);
	else
	{
		i_src = 0;
		i_dst = dst_len;
		while (src[i_src] != '\0' && i_dst < (dst_size - 1))
		{
			dst[i_dst] = src[i_src];
			i_dst++;
			i_src++;
		}
		dst[i_dst] = '\0';
	}
	return (src_len + dst_len);
}

// int	main(void)
// {
// 	char	src[] = " Tell me where did you sleep last night !";
// 	char	dest1[76] = "My girl, my girl don't lie to me !";
// 	char	dest2[76] = "My girl, my girl don't lie to me !";
// 	char	dest3[76] = "My girl, my girl don't lie to me !";
// 	char	dest4[76] = "My girl, my girl don't lie to me !";
// 	char	dest5[76] = "My girl, my girl don't lie to me !";
// 	char	dest6[76] = "My girl, my girl don't lie to me !";
// 	int		src_len;
// 	int		dest_len;

// 	src_len = ft_strlen(src);
// 	dest_len = ft_strlen(dest1);
// 	printf("\n Source : %s | Len : %d \n", src, src_len);
// 	printf("\n Destination : %s | Len : %d \n", dest1, dest_len);
// 	strlcat(dest1, src, 76);
// 	printf("\n Apres strlcat : %s | Len : %zu \n", dest1, ft_strlen(dest1));
// 	ft_strlcat(dest2, src, 76);
// 	printf("\n Apres ft_strlcat : %s | Len : %zu \n", dest2, ft_strlen(dest2));
// 	strlcat(dest3, src, 60);
// 	printf("\n Apres strlcat : %s | Len : %zu \n", dest3, ft_strlen(dest3));
// 	ft_strlcat(dest4, src, 60);
// 	printf("\n Apres ft_strlcat : %s | Len : %zu \n", dest4, ft_strlen(dest4));
// 	strlcat(dest5, src, 0);
// 	printf("\n Apres strlcat : %s | Len : %zu \n", dest5, ft_strlen(dest5));
// 	ft_strlcat(dest6, src, 0);
// 	printf("\n Apres ft_strlcat : %s | Len : %zu \n", dest6, ft_strlen(dest6));
// 	return (0);
// }
