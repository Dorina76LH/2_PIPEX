/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:36:35 by doberes           #+#    #+#             */
/*   Updated: 2025/04/24 11:25:11 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 	@file pipex.h
 	@brief Main header file for the Pipex project.

	Defines the main data structures, macros, constants, and function
	prototypes used throughout the project.

	This project is a smplified version of a shell pipeline. It takes a file as
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
# include <unistd.h> // // write, fork, execve, dup2, pipe, access
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
# define USAGE "DEBUG : Usage : \n./push_swap 'nb ... nb'\n"
//
//
// ------------- debug_mode --------------
// debug_mode activates debug_print fonctions
# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif
//
//
// _______________________________________
//
// -------------- structures -------------
// _______________________________________
//
//
// ---------- list ----------
//
/**
 * @struct t_list
 * @brief Represents a single node in the list
 * 
 * Each node contains a value and a pointer to
 * the next node in the stack.
 */
typedef struct s_list
{
	int				value;		//< Value stored in the node

	struct s_list	*next;		//< Pointer to the next node
}				t_list;
//
// ----------------- info ----------------
//
/**
 * @struct t_info
 * @brief Stores all metadata used to manage sorting and chunk operations.
 * 
 * This structure contains stack size, chunk ranges, min/max values,
 * cost calculations, and various flags used during sorting operations.
 */
typedef struct s_info
{
	/** Used in fill_stack_a() */
	int	stack_size;		///< Total size of the initial stack
	int	chunk_count;	///< Number of chunks created for the algorithm
	int	chunk_size;		///< Size of each chunk without adjustments
	int	extra;			///< Number of extra elements beyond perfect chunking
}				t_info;

// _______________________________________
//
// -------------- prototypes -------------
// _______________________________________
//
// -------------- file_name ----------------

#endif
