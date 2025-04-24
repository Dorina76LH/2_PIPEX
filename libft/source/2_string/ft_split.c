/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:35 by doberes           #+#    #+#             */
/*   Updated: 2024/11/09 13:58:37 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gcc -Wall -Werror -Wextra ft_split.c ft_strlen.c
*/

#include "libft.h"

static size_t	count_words(char const *string, char separator)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] != separator)
		{
			word_count++;
			while (string[i] != separator && string[i])
				i++;
		}
		else
			i++;
	}
	return (word_count);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*word_copy(char const	*str, char c)
{
	char	*word;
	int		i;

	word = (char *)malloc((word_len(str, c) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_result(char **result, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
	free(result);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	size_t	i_result;
	size_t	i_str;

	result = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i_result = 0;
	i_str = 0;
	while (str[i_str])
	{
		if (str[i_str] == c)
			i_str++;
		else
		{
			result[i_result] = word_copy(&str[i_str], c);
			if (!result[i_result])
				return (free_result(result, i_result), NULL);
			i_result++;
			i_str = i_str + word_len(&str[i_str], c);
		}
	}
	result[i_result] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char 	string[] = "To be or not to be that is the question.";
// 	char	separator = ' ';
// 	int		i;
// 	// ft_split("  tripouille  42  ", ' ');
// 	char	**result = ft_split(string, separator);
// 	int		words = count_words(string, separator);
// 	// Imprimer la chaine de depart et nb de mots
// 	printf("String : \'%s\'\n", string);
// 	printf("Nb de mots : %d\n", words);
// 	// Imprimer le tableau
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("Mot %d : \'%s\'\n", i+1, result[i]);
// 		printf("taille %zu\n", ft_strlen(result[i]));
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
