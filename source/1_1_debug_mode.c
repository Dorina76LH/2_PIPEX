/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_1_debug_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:43:40 by doberes           #+#    #+#             */
/*   Updated: 2025/05/04 15:31:04 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@file 1_1_debug_mode
	@brief Debug printing functions for Push_swap

	@note This file contains all utility functions that print internal states 
	and help visualize the data in debug mode. All functions are inactive 
	unless DEBUG_MODE is set to 1.

	Functions include:
	- General debug messages
	- Stack and array visualization
	- Chunk and position metadata after fill_stack_a()
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// ------------------------------ print_array ------------------------------
// =========================================================================

/**
	debug_print_array - Prints each element of an integer array

	@note This function displays the values in a given integer array, one per 
	line, if DEBUG_MODE is active.

	@param array A pointer to the array of integers.
	@param size The number of elements in the array.

	@return This function does not return a value.
*/
void	debug_print_array(int *array, int size)
{
	int	i;

	if (DEBUG_MODE == 1)
	{
		i = 0;
		while (i < size)
		{
			ft_printf("%i\n", array[i]);
			i++;
		}
		ft_printf("\n");
	}
}
