/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:13:14 by doberes           #+#    #+#             */
/*   Updated: 2025/04/24 11:25:11 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_TEST_H
# define PIPEX_TEST_H

// _______________________________________
//
// -------------- includes ---------------
// _______________________________________ 

// System libraries needed for tests
# include <stdlib.h> // malloc, free, exit, EXIT_FAILURE
# include <stdio.h> // perror
# include <unistd.h> // // write, fork, execve, dup2, pipe, access
# include <fcntl.h> // open
# include <sys/wait.h> // waitpid
# include <errno.h> // errno
# include <string.h> // strerror

// Main project header
# include "pipex.h" // pipex

// _______________________________________
//
// -------------- prototypes -------------
// _______________________________________
//
// -------------- file_name ----------------


#endif