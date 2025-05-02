/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_tools_memory_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:37 by doberes           #+#    #+#             */
/*   Updated: 2025/05/02 15:59:00 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 0_pipex_tools_memory_error.c
	@brief Error handling and memory management utilities for Pipex

	This file provides utility functions to:
	- Display error messages and exit cleanly on failure.
	- Free dynamically allocated memory for command arguments and paths.

	@note These functions help maintain clean resource management and prevent
	memory leaks in the Pipex project.
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
void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/*
int	error_msg(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(EXIT_FAILURE);
}
*/

// =========================================================================
// ---------------------------- free_str_array -----------------------------
// =========================================================================
/**
	free_str_array - Free an array of argument strings.

	@note Iterates through the null-terminated array @p str_array and frees
	each string, then frees the array itself.

	@param args A null-terminated array of dynamically allocated strings.
	@return None.
 */
void	free_str_array(char **str_array)
{
	int	i;

	i = 0;
	if (str_array)
	{
		while (str_array[i] != NULL)
		{
			free(str_array[i]);
			i++;
		}
		free(str_array);
	}
	return ;
}

// =========================================================================
// ------------------------------ free_memory ------------------------------
// =========================================================================
/**
	free_memory - Free memory allocated for command structures.

	@note This function releases all memory related to both commands
	(cmd1 and cmd2), including their argument arrays and resolved binary paths.

	@param pipex Pointer to the main Pipex structure.
	@return None.
 */
void	free_memory(t_pipex *pipex)
{
	if (pipex->cmd1)
	{
		free_str_array(pipex->cmd1->parsed_args);
		free(pipex->cmd1->binary_path);
		free(pipex->cmd1);
	}
	if (pipex->cmd2)
	{
		free_str_array(pipex->cmd2->parsed_args);
		free(pipex->cmd2->binary_path);
		free(pipex->cmd2);
	}
	return ;
}
