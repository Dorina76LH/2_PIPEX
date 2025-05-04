/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:18:21 by doberes           #+#    #+#             */
/*   Updated: 2025/05/04 17:02:37 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 0_pipex
	@brief Main program for Pipex

	@note This file implements the main process of the Pipex program. 

    @param argc The number of arguments passed to the program.
    @param argv The arguments passed to the program.

    @return Returns 0 upon successful execution.
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// --------------------------------- main ----------------------------------
// =========================================================================

/**
    main - Main entry point for Pipex program

    @note xxx

    @param argc The number of arguments passed to the program.
    @param argv The array of arguments passed to the program.
    @param envp

    @return Returns 0 if the program runs successfully, otherwise exits 
            with an error.
*/
/*
	infile => std_input
		|
	cmd1
	std_in = infile
	std_out = pipe (pipe_fd[1] = write)
		|
	pipe
	| pipe_fd[1] = write |
	|                    |
	|                    |
	| pipe_fd[0] = read  |
		|
	cmd2
	std_in = pipe (pipe_fd[0] = read)
	std_out = outfile

	nedded file descriptors 
					| infile_fd | outfile_fd | pipe_fd[0] | pipe_fd[1] |
					|   write   |    read    |    read    |    write   |
	--------------------------------------------------------------------
	PARENT			|     OK    |     OK     |      -     |      -     |
	--------------------------------------------------------------------
	CHILD1_WRITE	|     OK    |      -     |      -     |     OK     |
	--------------------------------------------------------------------
	CHILD2_READ		|     -     |     OK     |     OK     |      -     |
	--------------------------------------------------------------------
*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		error_msg("Usage: ./pipex infile cmd1 cmd2 outfile\n", 0);
	pipex = init_pipex(argv, envp);
    // check retpur malloc plus error avec free integre
    // if (!pipex.cmd1 || !pipex.cmd2)
    // error_msg_free("Failed to initialize commands", 0, &pipex);
	parse_command(pipex.cmd1, &pipex);
	parse_command(pipex.cmd2, &pipex);
	create_pipe(&pipex);
	create_children(&pipex);
	close_unused_fds_at_start(&pipex, PARENT);
	execute_children(&pipex);
	wait_for_children(&pipex);
	close_opened_fds_at_end(&pipex, PARENT);
	free_memory(&pipex);
	return (EXIT_SUCCESS);
}
