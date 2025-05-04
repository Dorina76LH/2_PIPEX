/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:53:22 by doberes           #+#    #+#             */
/*   Updated: 2025/05/04 17:11:59 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 1_init_pipex.c
	@brief Initialize the structures and file descriptors for the Pipex program

	This file includes:
	- `init_pipex` 			: initialize the main pipex structure.
	- `init_cmd_structures` : allocate and initialize the command structures.
	- `setup_stdio_fds` 	: open input and output files and set the
							  corresponding file descriptors.
	
	@note These functions are part of the program setup process, preparing the
	necessary structures and file descriptors for further operations in Pipex.
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// ------------------------- init_cmd_structures ---------------------------
// =========================================================================
/**
	init_cmd_structures - Allocates and initializes command structures.

	@note This function allocates memory for the command structures `cmd1`
	and `cmd2`, and initializes their variables to default values.

	@see init_pipex

	@param pipex The main `t_pipex` structure to hold the command structures.

	@return None.
	The command structures are directly modified in the `pipex` structure.
 */
static void	init_cmd_structures(t_pipex *pipex)
{
	pipex->cmd1 = malloc(sizeof(t_cmd));
	pipex->cmd2 = malloc(sizeof(t_cmd));
	if (pipex->cmd1 == NULL || pipex->cmd2 == NULL)
		error("Memory allocation failed");
	pipex->cmd1->input_cmd_str = NULL;
	pipex->cmd1->parsed_args = NULL;
	pipex->cmd1->binary_path = NULL;
	pipex->cmd1->is_valid = 0;
	pipex->cmd2->input_cmd_str = NULL;
	pipex->cmd2->parsed_args = NULL;
	pipex->cmd2->binary_path = NULL;
	pipex->cmd2->is_valid = 0;
	return ;
}

// =========================================================================
// --------------------------- setup_stdio_fds -----------------------------
// =========================================================================
/**
	setup_stdio_fds - Opens input and output files and sets file descriptors.

	@note This function attempts to open the input and output files specified
	by the user. It assigns file descriptors for reading from the input file 
	and writing to the output file.

	@see init_pipex

	@param pipex The`t_pipex` structure containing file descriptor variables.
	@param argv The array of arguments passed to the program.

	@return None. File descriptors are directly set in the `pipex` structure.
*/
static void	setup_stdio_fds(t_pipex *pipex, char **argv)
{
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
		error_msg("open infile", 1);
		//error("Failed to open infile");
	pipex->outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
		error_msg("open outfile", 1);
		//error("Failed to open outfile");
	return ;
}

// =========================================================================
// ------------------------------ init_pipex -------------------------------
// =========================================================================
/**
	init_pipex - Initializes the main structure for Pipex.

	@note This function allocates and initializes the necessary structures for
	the Pipex program, including setting up the input and output files,
	as well as storing the environment variables.

	@param argv The array of arguments passed to the program.
	@param envp The array of environment variables.

	@return A fully initialized `t_pipex` structure containing the necessary
	data.
 */
t_pipex	init_pipex(char **argv, char **envp)
{
	t_pipex	pipex;

	init_cmd_structures(&pipex);
	setup_stdio_fds(&pipex, argv);
	pipex.envp = envp;
	pipex.pid1 = -1;
	pipex.pid2 = -1;
	pipex.cmd1->input_cmd_str = argv[2];
	pipex.cmd2->input_cmd_str = argv[3];
	return (pipex);
}
