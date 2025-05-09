/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_tools_pipe_fds.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:29:51 by doberes           #+#    #+#             */
/*   Updated: 2025/05/05 18:03:42 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 0_pipex_tools_pipe_fds.c
	@brief Utility functions for managing pipes, processes, and memory in Pipex

	This file provides utility fonctions to :
	- Create a pipe for inter-process communication.
	- Redirect file descriptors (used for stdin/stdout redirection).
	- Close unused file descriptors at the start of each process.
	- Close all opened file descriptors at the end of each process.

	@note These helper functions ensure resource safety and simplify the main
	logic of the Pipex program by encapsulating common pipe and FD operations.
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// ----------------------------- create_pipe -------------------------------
// =========================================================================
/**
	create_pipe - Create a pipe for inter-process communication.

	@note This function initializes a unidirectional pipe, storing the file
	descriptors in the pipex structure. It is typically used to allow
	communication between two child processes.

	@param	pipex Pointer to the main Pipex structure that holds pipe_fds.
	@return	None.

	@warning On failure, this function exits the program with an error message.
 */
void	create_pipe(t_pipex *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
		exit_with_cleanup("pipe", 1, pipex);
	ft_printf("Pipex->pipe_fd[0]: %d (read)\n",pipex->pipe_fd[0]);
	ft_printf("Pipex->pipe_fd[1]: %d (write)\n",pipex->pipe_fd[1]);
	return ;
}

// =========================================================================
// ------------------------------ redirect_fd ------------------------------
// =========================================================================
/**
	redirect_fd - Redirect one file descriptor to another.

	@note This function duplicates the file descriptor @p old_fd into @p new_fd
	commonly used to redirect input/output streams.

	@param	old_fd The source file descriptor.
	@param	new_fd The destination file descriptor.
	@return	None.

	@warning On failure, this function exits the program with an error message.
 */
void	redirect_fd(int old_fd, int new_fd, t_pipex *pipex)
{
	ft_printf("old_fd : %d | new_fd : %d\n", old_fd, new_fd);
	fflush(stdout);
	if (old_fd < 0 || new_fd < 0)
		exit_with_cleanup("Invalid file descriptor", 0, pipex);
	if (dup2(old_fd, new_fd) == -1)
		exit_with_cleanup("dup", 1, pipex);
	return ;
}

// =========================================================================
// --------------------------- close_fd_safe -------------------------------
// =========================================================================
/**
	close_fd_safe - Safely close a file descriptor and set it to -1.

	@note This internal helper function closes the file descriptor pointed by
	@p fd only if it is currently valid (i.e., >= 0). It then marks
	it as closed by setting its value to -1.

	@see close_unused_fds_at_start
	@see close_opened_fds_at_end

	@param fd	Pointer to the file descriptor to close.
	@return		None.
 */
void	close_fd_safe(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
	return ;
}

// =========================================================================
// ------------------------- close_all_opened_fds --------------------------
// =========================================================================
/**
	close_unused_fds_at_start -  Close file descriptors that are not used at
								 the start of a process.

	@note Depending on the process type (PARENT, CHILD1_WRITE, or CHILD2_READ),
	this function selectively closes the FDs that will not be needed in
	the current process. It prevents leaks and enforces correct pipe usage.

	@param pipex	Pointer to the main Pipex structure.
	@param process	Integer flag identifying the current process type.
	            	Should be one of the defined macros: PARENT, CHILD1_WRITE,
	            	or CHILD2_READ.
	@return 		None.
 */
void	close_all_opened_fds(t_pipex *pipex)
{
		close_fd_safe(&pipex->infile_fd);
		close_fd_safe(&pipex->outfile_fd);
		close_fd_safe(&pipex->pipe_fd[0]);
		close_fd_safe(&pipex->pipe_fd[1]);
	return ;
}
