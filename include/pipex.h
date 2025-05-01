/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:36:35 by doberes           #+#    #+#             */
/*   Updated: 2025/04/29 11:31:34 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 	@file pipex.h
 	@brief Main header file for the Pipex project.

	Defines the main data structures, macros, constants, and function
	prototypes used throughout the project.

	This project is a simplified version of a shell pipeline. It takes a file as
	input, executes two commands using pipes, and writes the result to an
	output file.

	The program mimics the following shell behavior :
	< infile cmd1 | cmd2 > outfile
 */

#ifndef PIPEX_H
# define PIPEX_H

// _______________________________________
//
// -------------- includes ---------------
// _______________________________________ 

// System libraries needed for pipex
# include <stdlib.h> // malloc, free, exit, EXIT_FAILURE
# include <stdio.h> // perror
# include <unistd.h> // write, fork, execve, dup2, pipe, access
# include <fcntl.h> // open
# include <sys/wait.h> // waitpid
# include <errno.h> // errno
# include <string.h> // strerror

// Custom library
# include "../libft/include/libft.h" // libft

// _______________________________________
// 
// ---------------- macros ---------------
// _______________________________________
//
//
// -------------- messages ---------------
// Messages used for  error handling and debugging
//
// Error message with debug_mode off (debug_mode 0)
# define ERROR "Error\n"
//
// Error messages with debug_node on (debug_mode 1)
# define USAGE "DEBUG : Usage : \n./pipex infile cmd1 cmd2 outfile\n"
//
//
// ------------- debug_mode --------------
// debug_mode activates debug_print fonctions
# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif
//
# if DEBUG_MODE
#  warning "DEBUG_MODE is enabled. Disable it before submitting your project!"
# endif
//
// ---------- Macros for pipe closing mode ----------
# define CLOSE_READ  0
# define CLOSE_WRITE 1
# define CLOSE_BOTH  2
//
// _______________________________________
//
// -------------- structures -------------
// _______________________________________
//
//
// ----------- cmd ----------
/**
 * @brief Structure representing a single command to be executed.
 * 
 * This structure holds all necessary information for executing a command,
 * including the original command string, its arguments array, the resolved
 * absolute path to the executable, and a validation flag.
 * @todo complete with int fd_in/fd_out for bonus
 */
typedef struct s_cmd
{
	char	*raw_cmd;	//< The original command string ("ls -l")
	char	**args;		//< Split arguments for execve (["ls", "-l", NULL])
	char	*path;		//< Absolute path to the executable (e.g., "/bin/ls")
	int		is_valid;	//< Flag if the command is valid after parsing
}			t_cmd;

// ---------- pipex ---------
/**
 * @brief Main structure for managing the Pipex program execution.
 * 
 * This structure stores the file descriptors (fd), process IDs, environment 
 * variables, and the parsed command data required to simulate a pipeline 
 * between two commands.
 */
typedef struct s_pipex
{
	int		pipe_fd[2];		//< Pipe fd : pipe_fd[0]=read, pipe_fd[1]=write
	int		infile_fd;		//< File descriptor for input file
	int		outfile_fd;		//< File descriptor for output file
	pid_t	pid1;			//< Process ID of the first child (cmd1)
	pid_t	pid2;			//< Process ID of the second child (cmd2)
	char	**envp;			//< Environment variables array
	t_cmd	*cmd1;			//< First command structure
	t_cmd	*cmd2;			//< Second command structure
}			t_pipex;
//
// _______________________________________
//
// -------------- prototypes -------------
// _______________________________________
//
// ----------- 0_pipex_main_tools -------------
void	create_pipe(t_pipex *pipex);
void	close_pipe_ends(t_pipex *pipex, int mode);
void	redirect_fd(int old_fd, int new_fd);
void	free_memory(t_pipex *pipex);
int		error(char *msg);
// ------------- 1_init_pipex --------------
t_pipex	init_pipex(char **argv, char **envp);
//static void	init_cmd_structures(t_pipex *pipex);
//static void	setup_stdio_fds(t_pipex *pipex, char **argv);
// ------------- 3_child_process --------------
void	create_children(t_pipex *pipex);
void	execute_children(t_pipex *pipex);
void	wait_for_children(t_pipex *pipex);
//static void	execute_child1_write(t_pipex *pipex);
//static void	execute_child2_read(t_pipex *pipex);
#endif
