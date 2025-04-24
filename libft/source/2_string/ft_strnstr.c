/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:52:23 by doberes           #+#    #+#             */
/*   Updated: 2024/12/06 14:15:22 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_strnstr.c ft_strlen.c -lbsd
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_needle;
	size_t	i_haystack;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	i_haystack = 0;
	while (i_haystack < len && haystack[i_haystack] != '\0')
	{
		i_needle = 0;
		while (i_needle < needle_len && (i_haystack + i_needle) < len
			&& haystack[i_haystack + i_needle] == needle[i_needle])
			i_needle++;
		if (i_needle == needle_len)
			return ((char *)&haystack[i_haystack]);
		i_haystack++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*haystack = "Foo Bar Baz";
// 	char	*needle1 = "Bar";
// 	char	*needle2 = "Baz";
// 	char	*needle3 = "not exist";
// 	char	*needle4 = "";
// 	printf("Haystack : %s\n", haystack);
// 	// Test 1
// 	char	*res1 = strnstr(haystack, needle1, 4);
// 	printf("strnstr   : '%s' | Found : '%s'\n", needle1, res1 ? res1 :"NULL");
// 	char	*res5 = strnstr(haystack, needle1, 4);
// 	printf("ft_strnstr: '%s' | Found : '%s'\n", needle1, res5 ? res5 :"NULL");
// 	// Test 2
// 	char	*res2 = strnstr(haystack, needle2, 25);
// 	printf("strnstr   : '%s' | Found : '%s'\n", needle2, res2 ? res2 : "NULL");
// 	char	*res6 = ft_strnstr(haystack, needle2, 25);
// 	printf("ft_strnstr: '%s' | Found : '%s'\n", needle2, res6 ? res6 : "NULL");
// 	// Test 3
// 	char	*res3 = strnstr(haystack, needle3, 25);
// 	printf("strnstr   : '%s' | Found : '%s'\n", needle3, res3 ? res3 : "NULL");
// 	char	*res7 = ft_strnstr(haystack, needle3, 25);
// 	printf("ft_strnstr: '%s' | Found : '%s'\n", needle3, res7 ? res7 : "NULL");
// 	// Test 4	
// 	char	*res4 = strnstr(haystack, needle4, 25);
// 	printf("strnstr   : '%s' | Found : '%s'\n", needle4, res4 ? res4 : "NULL");
// 	char	*res8 = ft_strnstr(haystack, needle4, 25);
// 	printf("ft_strnstr: '%s' | Found : '%s'\n", needle4, res8 ? res8 : "NULL");
// 	return (0);
// }