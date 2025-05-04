/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_tools_pipe_fds.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:29:51 by doberes           #+#    #+#             */
/*   Updated: 2025/05/04 17:18:27 by doberes          ###   ########.fr       */
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
		error_msg("pipe", 1);
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
void	redirect_fd(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
		error_msg("dup", 1);
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
static void	close_fd_safe(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
	return ;
}

// =========================================================================
// ----------------------- close_unused_fds_at_start -----------------------
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
void	close_unused_fds_at_start(t_pipex *pipex, int process)
{
	if (process == PARENT)
	{
		close_fd_safe(&pipex->pipe_fd[0]);
		close_fd_safe(&pipex->pipe_fd[1]);
	}
	if (process == CHILD1_WRITE)
	{
		close_fd_safe(&pipex->outfile_fd);
		close_fd_safe(&pipex->pipe_fd[1]);
	}
	if (process == CHILD2_READ)
	{
		close_fd_safe(&pipex->infile_fd);
		close_fd_safe(&pipex->pipe_fd[0]);
	}
	return ;
}

// =========================================================================
// ---------------------- close_opened_fds_at_end --------------------------
// =========================================================================
/**
	close_opened_fds_at_start - Close all opened file descriptors at the end
								of a process.

	@note This function ensures that all opened files and pipes are properly
	closed when a process finishes its job, depending on the process type.

	@param pipex	Pointer to the main Pipex structure.
	@param process	Integer flag identifying the current process type.
	            	Should be one of the defined macros: PARENT, CHILD1_WRITE,
	            	or CHILD2_READ.
	@return			None.
*/
void	close_opened_fds_at_end(t_pipex *pipex, int process)
{
	if (process == PARENT)
	{
		close_fd_safe(&pipex->infile_fd);
		close_fd_safe(&pipex->outfile_fd);
	}
	if (process == CHILD1_WRITE)
	{
		close_fd_safe(&pipex->infile_fd);
		close_fd_safe(&pipex->pipe_fd[1]);
	}
	if (process == CHILD2_READ)
	{
		close_fd_safe(&pipex->outfile_fd);
		close_fd_safe(&pipex->pipe_fd[0]);
	}
	return ;
}
