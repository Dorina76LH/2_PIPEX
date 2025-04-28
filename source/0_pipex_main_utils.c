/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_main_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:29:51 by doberes           #+#    #+#             */
/*   Updated: 2025/04/28 16:00:49 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 0_pipex_main_utils.c
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
// ----------------------------- create_pipe -------------------------------
// =========================================================================
// Fonction pour créer les processus enfants
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
		error("Fork() failed for child1");
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error("Fork() failed for child2");
}

// =========================================================================
// ------------------------------ close_pipe -------------------------------
// =========================================================================
/**
	close_pipe - Close both ends of the pipe.

	@note This function closes the read and write file descriptors of
	the pipe to prevent resource leaks and ensure that processes behave
	as expected.

	@param pipex Pointer to the main Pipex structure containing pipe_fd.

	@return None.
	*/
void	close_pipe(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
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
}

// =========================================================================
// ------------------------------ free_memory ------------------------------
// =========================================================================
// rajouter toutes les donnees avec malloc, completer par une boucle (tableaux)
// free(pipex->cmd1->args);
// free(pipex->cmd2->args);

/**
	free_memory - Free memory allocated for command structures.

	@note This function releases the memory allocated for the command
	structures. It should be expanded to free any dynamically allocated
	arguments inside the command structures.

	@param pipex Pointer to the main Pipex structure containing commands.

	@return None.
*/
void	free_memory(t_pipex *pipex)
{
	free(pipex->cmd1);
	free(pipex->cmd2);
}

// idees pour free 
/*
// =========================================================================
// ------------------------------ free_args -------------------------------
// =========================================================================
// Libérer tous les arguments d'une commande (cmd1 ou cmd2)
void free_args(char **args)
{
    int i = 0;

    if (args)
    {
        while (args[i] != NULL)
        {
            free(args[i]);
            i++;
        }
        free(args);
    }
}
// =========================================================================
// ------------------------------ free_memory ------------------------------
// =========================================================================
void free_memory(t_pipex *pipex)
{
    // Libérer les args de cmd1 et cmd2
    free_args(pipex->cmd1->args);
    free_args(pipex->cmd2->args);

    // Libérer cmd1 et cmd2 eux-mêmes
    free(pipex->cmd1);
    free(pipex->cmd2);
}
*/