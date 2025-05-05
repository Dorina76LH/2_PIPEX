/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:53:22 by doberes           #+#    #+#             */
/*   Updated: 2025/05/05 16:59:23 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 0_pipex_init.c
	@brief Initialize the structures and file descriptors for the Pipex program

	This file includes:
	- `init_pipex`			: Main entry point for initializing the `pipex`
							  structure.
    - `init_cmd_structures`	: Allocates and initializes command structures.
    - `init_pipex_structure`: Initializes default values inside the `pipex`
							  structure.
    - `get_path_in_envp`	: Retrieves the PATH variable from the environment.
    - `setup_stdio_fds`		: Opens input/output files and sets the appropriate
							  file descriptors.
	
	@note These functions are called at the beginning of the program to prepare
    all necessary resources before forking and executing commands. Proper setup
	ensures that the program can redirect I/O and resolve binaries correctly.
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// -------------------------- get_path_in_envp -----------------------------
// =========================================================================
/**
	get_path_in_envp - Retrieves the PATH environment variable.

	@note This function scans the envp array to find the PATH variable,
	and returns a pointer to the string following "PATH=".

	@param envp The array of environment variables.

	@return A pointer to the value of PATH, or NULL if not found.
 */
static char	*get_path_in_envp(char **envp)
{
	int	i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}

// =========================================================================
// ------------------------- init_cmd_structures ---------------------------
// =========================================================================
/**
	init_cmd_structures - Allocates and initializes command structures.

	@note This function allocates memory for `cmd1` and `cmd2` and sets
	their internal fields to NULL or default values.

	@param pipex Pointer to the main `t_pipex` structure that will contain
	the command information.

	@return None. The command structures are set inside the given pipex struct.
			Exits on failure using 'exit_with_cleanup'
 */
static void	init_cmd_structures(t_pipex *pipex)
{
	pipex->cmd1 = malloc(sizeof(t_cmd));
	if (pipex->cmd1 == NULL)
		exit_with_cleanup("Memory allocation failed", 0, pipex);
	pipex->cmd2 = malloc(sizeof(t_cmd));
	if (pipex->cmd2 == NULL)
		exit_with_cleanup("Memory allocation failed", 0, pipex);
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
// ------------------------- init_pipex_structure --------------------------
// =========================================================================
/**
	init_pipex_structure - Initializes default values in the pipex structure.

	@note Sets all file descriptors and process IDs to -1, and pointer fields
	to NULL. This ensures a clean state before further initialization.

	@param pipex Pointer to the `t_pipex` structure to initialize.

	@return None. The command structures are set inside the given pipex struct.
 */
static void	init_pipex_structure(t_pipex *pipex)
{
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd[1] = -1;
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
	pipex->envp = NULL;
	pipex->path = NULL;
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
			Exits on failure using 'exit_with_cleanup'.
*/
static void	setup_stdio_fds(t_pipex *pipex, char **argv)
{
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
		exit_with_cleanup("Failed to open input file", 1, pipex);
	ft_printf("Pipex->infile_fd : %d (read)\n", pipex->infile_fd);
	pipex->outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
		exit_with_cleanup("Failed to open output file", 1, pipex);
	ft_printf("Pipex->outfile_fd : %d (write)\n", pipex->outfile_fd);
	return ;
}

// =========================================================================
// ------------------------------ init_pipex -------------------------------
// =========================================================================
/**
	init_pipex - Main initializer for the Pipex structure.

	@note This function sets up the entire environment for the program,
	including file descriptors, environment variables, command arguments,
	and the PATH used for binary resolution.

	@param argv Argument array from main
				(used to get infile, cmd1, cmd2, outfile).
	@param envp Environment variable array.

	@return A fully initialized `t_pipex` structure ready for execution.
 */
t_pipex	init_pipex(char **argv, char **envp)
{
	t_pipex	pipex;

	init_pipex_structure(&pipex);
	init_cmd_structures(&pipex);
	setup_stdio_fds(&pipex, argv);
	pipex.envp = envp;
	pipex.path = get_path_in_envp(envp);
	ft_printf("Pipex->path : %s\n", pipex.path);
	if (!pipex.path)
		exit_with_cleanup("PATH not found in environnement", 0, &pipex);
	pipex.cmd1->input_cmd_str = argv[2];
	ft_printf("Pipex->cmd1 : %s\n", pipex.cmd1->input_cmd_str);
	pipex.cmd2->input_cmd_str = argv[3];
	ft_printf("Pipex->cmd2 : %s\n", pipex.cmd2->input_cmd_str);
	return (pipex);
}
