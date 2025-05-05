/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_tools_memory_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:37 by doberes           #+#    #+#             */
/*   Updated: 2025/05/05 17:11:10 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 0_pipex_tools_memory_error.c
	@brief Error handling and memory management utilities for Pipex

	@note These functions help maintain clean resource management and prevent
	memory leaks in the Pipex project.

	Included functions:
	- error_argc		: Display an argument-related error message and exit.
	- exit_with_cleanup	: Print an error (optionally using errno), free all
						  resources, and exit.
	- free_str_array	: Free a null-terminated array of dynamically allocated
						  strings.
	- free_memory		: Free command structures, parsed arguments, and binary
						  paths.
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
void	error_argc(char *msg)
{
	ft_printf(msg);
	exit(EXIT_FAILURE);
}
// =========================================================================
// --------------------------- exit_with_cleanup ---------------------------
// =========================================================================

void	exit_with_cleanup(char *msg, int use_errno, t_pipex *pipex)
{
	if (use_errno)
	{
		perror(msg);
	}
	else
	{
		write(2, "pipex: ", 7);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	close_all_opened_fds(pipex);
	free_memory(pipex);
	exit(EXIT_FAILURE);
}

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
			str_array[i] = NULL;
			i++;
		}
		free(str_array);
		str_array = NULL;
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
		if (pipex->cmd1->parsed_args)
			free_str_array(pipex->cmd1->parsed_args);
		if (pipex->cmd1->binary_path)
			free(pipex->cmd1->binary_path);
		free(pipex->cmd1);
	}
	if (pipex->cmd2)
	{
		if (pipex->cmd2->parsed_args)
			free_str_array(pipex->cmd2->parsed_args);
		if (pipex->cmd2->binary_path)
			free(pipex->cmd2->binary_path);
		free(pipex->cmd2);
	}
	return ;
}
