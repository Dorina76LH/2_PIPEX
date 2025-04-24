/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:16:27 by doberes           #+#    #+#             */
/*   Updated: 2025/01/06 16:33:10 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ============================================================================
// --------------------------------- Headers ----------------------------------
// ============================================================================
#include "get_next_line.h"

// ============================================================================
// ------------------------------ ft_calloc -----------------------------------
// ============================================================================

// ft_calloc : allocates the memory and fills the allocated memory with
// bytes of value zero '\0'

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < (count * size))
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// ============================================================================
// ------------------------------ ft_strlen -----------------------------------
// ============================================================================

//  ft_strlen : calculates the length of the string pointed by s - excluding
//  the terminating null byte ('\0')- and returns the length

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// ============================================================================
// ------------------------------ ft_strjoin ----------------------------------
// ============================================================================

//  ft_strjoin : copies in *result : string1 + string2 + '\0 and returns *result
//   - Calculate the length of string1 and string2 (without '\0')
//   - Allocate memory for the copy : total_len = len_str1 + len_str2 + 1(='\0)
//   - Copy str1 (without '\0'), str2 (without '\0') and '\0' in result
//   - Return value : result

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i_str1;
	int		i_str2;
	int		len_str1;
	int		len_str2;
	char	*result;

	len_str1 = ft_strlen(s1);
	len_str2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (result == NULL)
		return (NULL);
	i_str1 = 0;
	while (i_str1 < len_str1)
	{
		result[i_str1] = s1[i_str1];
		i_str1++;
	}
	i_str2 = 0;
	while (i_str2 < len_str2)
	{
		result[i_str1 + i_str2] = s2[i_str2];
		i_str2++;
	}
	result[i_str1 + i_str2] = '\0';
	return (result);
}

// ============================================================================
// ------------------------------ ft_substr -----------------------------------
// ============================================================================

// ft_substr : allocates (with malloc), and returns a substring from 's'
// The substring begins to 'start' and is of maximum length 'len'
// If 'start' exceeds the length of 's', an empty string is returned 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*extract_str;

	if (s == NULL)
		return (NULL);
	str_len = 0;
	while (s[str_len] != '\0')
		str_len++;
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > str_len)
		len = str_len - start;
	extract_str = malloc(len + 1);
	if (!extract_str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		extract_str[i] = s[start + i];
		i++;
	}
	extract_str[i] = '\0';
	return (extract_str);
}

// ============================================================================
// ------------------------------ ft_strchr -----------------------------------
// ============================================================================

// Ft_strchr : locates the first occurence of c (converted to a char) in 's'
// and returns a pointer to the located character, or NULL if the character
// does not appear in the string.

char	*ft_strchr(const char *s, int c)
{
	unsigned char	unsig_char;

	unsig_char = (unsigned char)c;
	while (*s != '\0' && unsig_char != *s)
		s++;
	if (*s == unsig_char)
		return ((char *)s);
	return (0);
}
