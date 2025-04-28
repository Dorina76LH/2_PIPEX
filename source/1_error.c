/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:40:49 by doberes           #+#    #+#             */
/*   Updated: 2025/04/28 16:08:53 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 1_error.c
	@brief Contains error handling functions for Pipex.

	This file includes:
	- The `error` function to handle and display error messages
	  and terminate the program.
	
	@note The `error` function is used throughout the program to manage
	exceptional situations that prevent further execution. It ensures
	that a descriptive error message is displayed, and the program exits gracefully.
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
int	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
