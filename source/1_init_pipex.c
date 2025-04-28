/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:53:22 by doberes           #+#    #+#             */
/*   Updated: 2025/04/28 16:08:53 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 1_init_pipex.c
	@brief Initialize the structures and file descriptors for the Pipex program.

	This file includes:
	- `init_pipex` function to initialize the main pipex structure.
	- `init_cmd_structures` function to allocate and initialize the command structures.
	- `handle_file_descriptors` function to open input and output files and set the corresponding file descriptors.
	
	@note These functions are part of the program setup process, preparing the necessary structures and file descriptors
	for further operations in Pipex.
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

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

	@return A fully initialized `t_pipex` structure containing the necessary data.
 */
t_pipex	init_pipex(char **argv, char **envp)
{
	t_pipex	pipex;

	init_cmd_structures(&pipex);
	handle_file_descriptors(&pipex, argv);
	pipex.envp = envp;
	pipex.cmd1->raw_cmd = argv[2];
	pipex.cmd2->raw_cmd = argv[3];
	return (pipex);
}
// =========================================================================
// ------------------------- init_cmd_structures ---------------------------
// =========================================================================

// allouer la memoire les pour les structures cmd1 et cmd2
// initialiser variables des structures cmd1 et cmd2
/**
	init_cmd_structures - Allocates and initializes command structures.

	@note This function allocates memory for the command structures `cmd1` and `cmd2`,
		and initializes their variables to default values.

	@param pipex The main `t_pipex` structure to hold the command structures.

	@return None. The command structures are directly modified in the `pipex` structure.
 */
void	init_cmd_structures(t_pipex *pipex)
{
	pipex->cmd1 = malloc(sizeof(t_cmd));
	pipex->cmd2 = malloc(sizeof(t_cmd));
	if (pipex->cmd1 == NULL || pipex->cmd2 == NULL)
		error("Memory allocation failesd");
	pipex->cmd1->raw_cmd = NULL;
	pipex->cmd1->args = NULL;
	pipex->cmd1->path = NULL;
	pipex->cmd1->is_valid = 0;
	pipex->cmd2->raw_cmd = NULL;
	pipex->cmd2->args = NULL;
	pipex->cmd2->path = NULL;
	pipex->cmd2->is_valid = 0;
}

// =========================================================================
// ----------------------- handle_file_descriptors -------------------------
// =========================================================================
// Fonction pour rediriger les file descriptors
/**
	handle_file_descriptors - Opens input and output files and sets file descriptors.

	@note This function attempts to open the input and output files specified
	by the user. It assigns file descriptors for reading from the input file 
	and writing to the output file.

	@param pipex The main `t_pipex` structure containing file descriptor variables.
	@param argv The array of arguments passed to the program.

	@return None. File descriptors are directly set in the `pipex` structure.
*/
void	handle_file_descriptors(t_pipex *pipex, char **argv)
{
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
		error("Failed to open infile");

	pipex->outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
		error("Failed to open outfile");
}
