/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:07:32 by doberes           #+#    #+#             */
/*   Updated: 2025/01/06 17:20:47 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ============================================================================
// -------------------------------- headers -----------------------------------
// ============================================================================
#include "libft.h"
#include "get_next_line.h"

// ============================================================================
// ---------------------------- get_next_line ---------------------------------
// ============================================================================

// 1. Validate the inputs and check the file descriptor
// 2. Read from fd and append to 'buffer_static'
// 3. Extract 'line' from 'buffer_static'
// 4. Clean 'buffer_static'
// return (free(buffer_static[fd]), buffer_static[fd] = NULL, free(line), NULL);

char	*get_next_line(int fd)
{
	static char	*buffer_static[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer_static[fd] = read_and_join(fd, buffer_static[fd]);
	if (buffer_static[fd] == NULL)
		return (NULL);
	line = find_new_line(buffer_static[fd], line);
	if (line == NULL || *line == '\0')
	{
		free(buffer_static[fd]);
		return (buffer_static[fd] = NULL, free(line), NULL);
	}
	buffer_static[fd] = clean_buffer_static(buffer_static[fd]);
	return (line);
}

// ============================================================================
// ------------------------------ read_and_join -------------------------------
// ============================================================================

//	Read buffer_size from fd and append the characters read in 'buffer_static'
//  1. Allocate memory for 'buffer_read'
//	2. Initialise 'buffer_static'
//	3. Loop : read if the return value of read() > 0
//	   Initialize count_char to 1, to ensure entring the loop at least once
//	   If reading error (-1) =>> free buffers and return NULL
//     buffer_tmp = concatenate buffer_static and buffer_read

char	*read_and_join(int fd, char *buffer_static)
{
	char		*buffer_read;
	char		*buffer_tmp;
	ssize_t		count_char;

	buffer_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer_read == NULL)
		return (free(buffer_static), NULL);
	if (!buffer_static)
		buffer_static = ft_substr("", 0, 0);
	if (!buffer_static)
		return (free(buffer_static), NULL);
	count_char = 1;
	while (ft_strchr(buffer_static, '\n') == 0 && count_char > 0)
	{
		count_char = read(fd, buffer_read, BUFFER_SIZE);
		if (count_char == -1)
			return (free(buffer_static), free(buffer_read), NULL);
		buffer_read[count_char] = '\0';
		buffer_tmp = ft_strjoin(buffer_static, buffer_read);
		if (buffer_tmp == NULL)
			return (free(buffer_static), free(buffer_read), NULL);
		free(buffer_static);
		buffer_static = buffer_tmp;
	}
	return (free(buffer_read), buffer_static);
}

// ============================================================================
// ----------------------------- find_new_line ---------------------------------
// ============================================================================

// Check after read(), if there is a new line im buffer_static
// 1. Check for new line ( '\n' or EOF ) in buffer_static 
// 2. Calculate length of new line
// 3. Copy new line in 'line'
// 4. Return line

char	*find_new_line(char *buffer_static, char *line)
{
	int	len_line;

	len_line = 0;
	while (buffer_static[len_line] != '\n' && buffer_static[len_line] != '\0')
		len_line++;
	if (buffer_static[len_line] == '\n')
		len_line++;
	line = ft_substr(buffer_static, 0, len_line);
	if (line == NULL)
		return (NULL);
	return (line);
}

// ============================================================================
// ----------------------------- clean_buffer ---------------------------------
// ============================================================================

// after extracting the line, remove the characters read
// the static_buffer have to contain only the characters not jet extracted
// 1. Find len_extract 
//    - Check length of 'line' in 'buffer_static' (strlen + 1 =>> include '\n')
//    - Check length if 'buffer_static'
//    - len_extract = length_total - len_line
// 2. Clean buffer_static
//    - Copy the content of 'buffer_static' after 'start' in 'buffer_extract'
//    - Free 'buffer_static'
//    - Return 'buffer_extract'
char	*clean_buffer_static(char *buffer_static)
{
	char	*buffer_extract;
	int		len_line;
	int		start;
	int		len_total;
	int		len_extract;

	len_line = 0;
	while (buffer_static[len_line] != '\n' && buffer_static[len_line] != '\0')
		len_line++;
	start = len_line + 1;
	len_total = 0;
	while (buffer_static[len_total] != '\0')
		len_total++;
	len_extract = len_total - start;
	buffer_extract = ft_substr(buffer_static, start, len_extract);
	if (buffer_extract == NULL)
		return (free(buffer_static), NULL);
	free(buffer_static);
	return (buffer_extract);
}
//============================================================================
//--------------------------------- main -------------------------------------
//============================================================================
// gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=42
// get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c
// int	main(int argc, char **argv)
// {
// 	// Variable declaration
// 	int		fd1;
// 	int		fd2;
// 	char	*new_line1;
// 	char	*new_line2;
// 	int		count_line1;
// 	int		count_line2;
// 	// Variable initialisation
// 	count_line1 = 0;
// 	count_line2 = 0;
// 	// when argc == 1 => no file
// 	if (argc == 1)
// 	{
// 		fd1 = STDIN_FILENO;
// 		fd2 = STDIN_FILENO;
// 	}
// 	// when argc == 2 => 1 file
// 	else if (argc == 2)
// 	{
// 		fd1 = STDIN_FILENO;
// 		fd2 = open(argv[1], O_RDONLY);
// 		// if (fd2 < 0 && argc == 2)
// 		// {
// 		// 	perror("Error opening file")
// 		// 	return (1);
// 		// }
// 	}
// 	//when argc == 3 => 2 files
// 	// Open files in read only mode and check for errors
// 	else if (argc == 3)
// 	{
// 		fd1 = open(argv[1], O_RDONLY);
// 		fd2 = open(argv[2], O_RDONLY);
// 		//if (fd1 < 0 || fd2 < 0)
// 		//{
// 		// 	perror("Error opening file");
// 		// 	if (fd1 >= 0)
// 		// 		close(fd1);
// 		// 	if (fd2 >= 0)
// 		// 		close(fd2);
// 		// 	return(1);
// 		// }
// 	}
// 	// Read and print lines from both file until both are empty
// 	while(1)
// 	{
// 		// Get the next line from each file
// 		new_line1 = get_next_line(fd1);
// 		new_line2 = get_next_line(fd2);
// 		// Break out of the loop when both files have been fully read
// 		if (new_line1 == NULL && new_line2 == NULL)
// 			break;
// 		// Print line from file1, if available
// 		if(new_line1 != NULL)
// 		{
// 			printf("File 1 : Line #%d : %s\n", ++count_line1, new_line1);
// 			free(new_line1);
// 		}
// 		// Print line from file2, if available
// 		if(new_line2 != NULL)
// 		{
// 			printf("File 2 : Line #%d : %s\n", ++count_line2, new_line2);
// 			free(new_line2);
// 		}
// 	}
// 	// Close files after reading
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
