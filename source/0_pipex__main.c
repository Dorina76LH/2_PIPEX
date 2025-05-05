/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex__main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:18:21 by doberes           #+#    #+#             */
/*   Updated: 2025/05/05 16:56:36 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 0_pipex__main.c
	@brief Entry point for the Pipex program.

	This file includes:
	- 'main'
 
	@note
    Pipex is a simplified recreation of shell piping behavior. It takes an
	input file, two commands, and an output file as arguments, and executes
	the equivalent of: < infile cmd1 | cmd2 > outfile

    The program uses UNIX system calls such as `pipe`, `fork`, `dup2`, and
	`execve` to create two child processes, connect them through a pipe, and 
	redirect their standard input/output as needed.

    The goal is to emulate how a shell connects multiple processes through
	pipes, passing the output of one command as input to the next, while
	managing file descriptors and memory correctly.
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// --------------------------------- main ----------------------------------
// =========================================================================

/*
	File Descriptor Flow:
	infile --> [ cmd1 ] --> pipe --> [ cmd2 ] --> outfile

	        infile (argv[1])
               |
           [ cmd1 ] (argv[2])
           stdin  <- infile
           stdout -> pipe_fd[1]
               |
          ┌────────────┐
          │   PIPE     │
          │ write fd:  pipe_fd[1]
          │ read  fd:  pipe_fd[0]
          └────────────┘
               |
           [ cmd2 ] (argv[3])
           stdin  <- pipe_fd[0]
           stdout -> outfile
               |
           outfile (argv[4])

	Redirected Standard I/O per process:
	- cmd1:
		stdin  <- infile_fd
		stdout -> pipe_fd[1]
	- cmd2:
		stdin  <- pipe_fd[0]
		stdout -> outfile_fd
	
	Open file descriptors 
					| infile_fd | outfile_fd | pipe_fd[0] | pipe_fd[1] |
					|    read   |    write   |    read    |    write   |
	--------------------------------------------------------------------
	PARENT			|     OK    |     OK     |     OK     |     OK     |
	--------------------------------------------------------------------
	CMD1 (CHILD1)	|     OK    |      -     |      -     |     OK     |
	--------------------------------------------------------------------
	CMD2 (CHILD2)	|     -     |     OK     |     OK     |      -     |
	--------------------------------------------------------------------
*/

/**
    main - Main entry point of the Pipex program

    @note Validates arguments, initializes structures, parses commands, 
	sets up the pipe and processes, and handles cleanup.

    @param argc Number of arguments passed to the program.
    @param argv Array of argument strings.
    @param envp Environment variables.

    @return 0 if the program runs successfully, otherwise exits 
            with an error.
*/
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		error_argc("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	ft_printf("Valid arguments : %s | %s | %s | %s\n",
		argv[1], argv[2], argv[3], argv[4]);
	pipex = init_pipex(argv, envp);
	parse_command(pipex.cmd1, &pipex);
	parse_command(pipex.cmd2, &pipex);
	create_pipe(&pipex);
	create_children(&pipex);
	execute_children(&pipex);
	close_all_opened_fds(&pipex);
	wait_for_children(&pipex);
	free_memory(&pipex);
	return (0);
}
