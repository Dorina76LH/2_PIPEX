/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:18:30 by doberes           #+#    #+#             */
/*   Updated: 2025/01/10 09:38:48 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ============================================================================
// ------------------------ Create static library -----------------------------
// ============================================================================
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// ============================================================================
// ------------------------- Macro : Buffer size ------------------------------
// ============================================================================

//    If not defined (main fonction or gcc), buffer size is 10

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// ============================================================================
// -------------------- Macro : File descriptor limit -------------------------
// ============================================================================

//    Max fd >> Linux : ulimit -n
//    Max fd >> Mac : launchctl limit maxfiles

# define FD_MAX 1024

// ============================================================================
// -------------------------- Included libraries ------------------------------
// ============================================================================

// printf()
//# include <stdio.h>

// read() STDIN_FILENO
# include <unistd.h>

// open()
//# include <fcntl.h>

// malloc(), free(), size_t
# include <stdlib.h>

// ============================================================================
// -------------------------- Included fonctions ------------------------------
// ============================================================================

// ----------------------------- Main fonction --------------------------------
char	*get_next_line(int fd);

// ------------------------ Non-static sub fonctions --------------------------
char	*read_and_join(int fd, char *buffer_staric);
char	*find_new_line(char *buffer_static, char *line);
char	*clean_buffer_static(char *buffer_static);

// --------------------------- Utility fonctions ------------------------------
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);

#endif
