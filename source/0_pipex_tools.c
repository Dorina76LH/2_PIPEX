/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:29:51 by doberes           #+#    #+#             */
/*   Updated: 2025/04/29 15:32:59 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 0_pipex_tools.c
	@brief Utility functions for managing pipes, processes, and memory in Pipex.

	This file contains:
	- The creation of a pipe for inter-process communication.
	- The creation of two child processes.
	- The closing of pipe file descriptors.
	- The waiting for child process termination.
	- The freeing of memory allocated for command structures.

	@note These utility functions help keep the main Pipex code clean and
	organized, ensuring that resources are correctly handled and errors are
	reported early.
	*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// --------------------------------- error ---------------------------------
// =========================================================================
/**
	error - Display an error message and terminate the program.

	@note This function uses `perror` to print the given error message 
	and then exits the program with a failure status.

	@param msg The error message to be displayed.

	@return None. The program is terminated after this function is called.
*/
int	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/*
int	error_errno(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
int	error_msg(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(EXIT_FAILURE);
}
*/

// =========================================================================
// ----------------------------- create_pipe -------------------------------
// =========================================================================
// Fonction pour créer la pipe
/**
	create_pipe - Create a pipe for inter-process communication.

	@note This function initializes a pipe used to transfer data between
	two child processes. If the pipe creation fails, an error message
	is displayed and the program exits.

	@param pipex Pointer to the main Pipex structure containing pipe_fd.

	@return None.
	*/
void	create_pipe(t_pipex *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
		error("Pipe() failed");
}

// =========================================================================
// ------------------------------ close_pipe -------------------------------
// =========================================================================
/**
	close_pipe - Close one or both ends of the pipe.

	@note This function allows selective closure of the pipe file descriptors
	based on the mode provided. It's used to avoid file descriptor leaks
	and ensure correct inter-process communication behavior.

	@param pipex Pointer to the main Pipex structure containing pipe_fd.
	@param mode	 Determines which end(s) of the pipe to close:
					- 0 : Close the read end only (pipe_fd[0])
					- 1 : Close the write end only (pipe_fd[1])
					- 2 : Close both ends of the pipe

	@return None.
	*/
void	close_pipe_ends(t_pipex *pipex, int mode)
{
	if (mode == 0 || mode == 2)
		close(pipex->pipe_fd[0]);
	if (mode == 1 || mode == 2)
		close(pipex->pipe_fd[1]);
}

// =========================================================================
// ------------------------------ redirect_fd ------------------------------
// =========================================================================
/**
	redirect_fd - Redirect a file descriptor
	
	@note This function duplicates old_fd to new_fd.
	If the operation fails, the program terminates with an error message.
	
	@old_fd: The file descriptor to duplicate.
	@new_fd: The new file descriptor for redirection.

	@return None.
 */
void	redirect_fd(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
		error("dup2 failed");
}

void	close_all_fds(t_pipex *pipex, int context)
{
	if (context != CHILD1)
		close_safe(pipex->infile_fd);
	if (context != CHILD2)
		close_safe(pipex->outfile_fd);
	if (context != CHILD2) // seul child2 lit depuis pipe_fd[0]
		close_safe(pipex->pipe_fd[0]);
	if (context != CHILD1) // seul child1 écrit dans pipe_fd[1]
		close_safe(pipex->pipe_fd[1]);
}

void	close_safe(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}