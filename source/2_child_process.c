/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_child_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:59:05 by doberes           #+#    #+#             */
/*   Updated: 2025/05/05 16:17:48 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 2_child_process.c
	@brief Manages the child process creation and execution for the Pipex
	program.

	This file contains the functions responsible for:
	- Forking the child processes to execute the commands.
	- Redirecting file descriptors for the child's input and output.
	- Executing the commands in each child process using `execve`.
	- Waiting for both child processes to finish execution.

	Functions included:
	- `create_children` 	: Forks two child processes to execute the commands
	- `execute_child1_write`: Executes the first child process to read from
							  infile and write to the pipe
	- `execute_child2_read` : Executes the second child process to read from
							  the pipe and write to the output file
	- `execute_children` 	: Calls the appropriate execution function for each
							  child
	- `wait_for_children` 	: Waits for both child processes to finish
							  execution

	@note These functions work together to execute the Pipex program, which
	processes files using two commands in a pipeline. The child processes handle
	the execution of the commands, while the parent waits for them to finish and
	manages synchronization.
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// --------------------------- create_children -----------------------------
// =========================================================================
/**
	create_children - Create two child processes for executing commands.

	@note This function forks the process twice. The first fork creates the
	first child, and the second fork creates the second child. If any fork
	fails, an error message is displayed and the program exits.

	@param pipex Pointer to the main Pipex structure containing PIDs.

	@return None.
	*/
void	create_children(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		exit_with_cleanup("fork", 1, pipex);
	if (pipex->pid1 == 0)
		return ;
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		exit_with_cleanup("fork", 1, pipex);
	return ;
}

// =========================================================================
// -------------------------- execute_child1_write -------------------------
// =========================================================================
/**
	execute_child1_write - Executes the first child process to read from
						   infile and write to the pipe.

	@note This function redirects the standard input to the infile and the
	standard output to the write-end of the pipe (pipe_fd[1]). After that,
	it closes the unused read-end of the pipe and executes the first
	command (using execve).

	@param pipex Pointer to the main Pipex structure containing file
	descriptors and command information.

	@return None. This function terminates the process if execve fails.
 */
static void	execute_child1_write(t_pipex *pipex)
{
	redirect_fd(pipex->infile_fd, STDIN_FILENO, pipex);
	redirect_fd(pipex->pipe_fd[1], STDOUT_FILENO, pipex);
	close_all_opened_fds(pipex);
	if (execve(pipex->cmd1->binary_path, pipex->cmd1->parsed_args, pipex->envp)
		== -1)
	{
		exit_with_cleanup("execve", 1, pipex);
	}
}

// =========================================================================
// -------------------------- execute_child2_read --------------------------
// =========================================================================
/**
	execute_child2_read - Executes the second child process to read from the
						  pipe and write to the outfile.

	@note This function redirects the standard input to the read-end of the
	pipe(pipe_fd[0]) and the standard output to the outfile. Then, it closes
	the write-end of the pipe and executes the second command (using execve).

	@param pipex Pointer to the main Pipex structure containing file
	descriptorsand command information.

	@return None. This function terminates the process if execve fails.
 */
static void	execute_child2_read(t_pipex *pipex)
{
	redirect_fd(pipex->pipe_fd[0], STDIN_FILENO, pipex);
	redirect_fd(pipex->outfile_fd, STDOUT_FILENO, pipex);
	close_all_opened_fds(pipex);
	if (execve(pipex->cmd2->binary_path, pipex->cmd2->parsed_args, pipex->envp)
		== -1)
	{
		exit_with_cleanup("execve", 1, pipex);
	}
}

// =========================================================================
// --------------------------- execute_children ----------------------------
// =========================================================================
/**
	execute_children - Executes the child processes based on their PIDs.

	@note This function checks the PIDs stored in the `pipex` structure. If
	the process is the first child, it calls `execute_child1_write`. If it's
	the second child, it calls `execute_child2_read`.

	@param pipex Pointer to the main Pipex structure containing PIDs.

	@return None.
 */
void	execute_children(t_pipex *pipex)
{
	if (pipex->pid1 == 0)
		execute_child1_write(pipex);
	if (pipex->pid2 == 0)
		execute_child2_read(pipex);
	return ;
}

// =========================================================================
// ----------------------------- wait_for_children ------------------------
// =========================================================================
/**
	wait_for_children - Wait for both child processes to finish.

	@note This function waits for the two child processes to terminate
	before proceeding, ensuring proper synchronization and avoiding
	zombie processes.

	@param pipex Pointer to the main Pipex structure containing PIDs.

	@return None.
	*/
void	wait_for_children(t_pipex *pipex)
{
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	return ;
}
