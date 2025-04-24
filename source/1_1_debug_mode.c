/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_1_debug_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:43:40 by doberes           #+#    #+#             */
/*   Updated: 2025/04/24 11:31:57 by doberes          ###   ########.fr       */
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
// ---------------------------- debug_print_main ---------------------------
// =========================================================================

/**
	debug_print_main - Prints initial state of input and stacks

	@note This function is called at the end of the program if  DEBUG_MODE
	is active. It prints the memory address of the input array and stack
	pointers. These addresses should be null after the memory has been freed.

	@param stack_a A pointer to the main stack A.
	@param stack_b A pointer to the main stack B.
	@param input A structure holding the integer array used for initialization.

	@return This function does not return a value.
*/
void	debug_print_main(t_stack **stack_a, t_stack **stack_b,
		t_input input)
{
	if (DEBUG_MODE == 1)
	{
		ft_printf("DEBUG : int array : %p\n", input.int_array);
		ft_printf("DEBUG : *stack_a : %p\n", stack_a);
		ft_printf("DEBUG : *stack_b : %p\n", stack_b);
		ft_printf("DEBUG : 0_main >> end\n");
	}
}

// =========================================================================
// ------------------------ debug_print_fill_stack_a -----------------------
// =========================================================================

/**
	debug_print_fill_stack_a - Prints stack A and chunk metadata

	@note Called after the stack is filled, this function displays the content 
	of stack A and chunk-related metadata stored in the info struct.

	@param stack_a A pointer to the main stack A.
	@param info A pointer to a structure holding stack metadata.
	@param c A character indicating which stack is being printed.

	@return This function does not return a value.
*/
void	debug_print_fill_stack_a(t_stack **stack_a, t_info *info, char c)
{
	if (DEBUG_MODE == 1)
	{
		ft_printf("Stack A :\n");
		debug_print_stack(*stack_a, c);
		ft_printf("DEBUG : List size : %d\n", info->stack_size);
		ft_printf("DEBUG : Chunk count : %d\n", info->chunk_count);
		ft_printf("DEBUG : Chunk to head : %d\n", info->chunk_to_head);
		ft_printf("DEBUG : Chunk to tail : %d\n\n", info->chunk_to_tail);
	}
}

// =========================================================================
// -------------------------- debug_print_messages -------------------------
// =========================================================================

/**
	debug_print_messages - Prints a message depending on a debug code

	@note This function matches the debug_code to a specific debug message 
	(usage, errors, or validation feedback).

	@param debug_code An integer representing the type of message to print.
	@param argc The number of arguments passed to the program.

	@return This function does not return a value.
*/
void	debug_print_messages(int debug_code, int argc)
{
	if (DEBUG_MODE == 1)
	{
		if (debug_code == 1)
			ft_printf("%s", USAGE);
		else if (debug_code == 2)
			ft_printf("%s", INVALID_ARG);
		else if (debug_code == 3)
			ft_printf("%s", MALLOC);
		else if (debug_code == 4)
			ft_printf("%s", INVALID_INPUT);
		else if (debug_code == 5)
			ft_printf("%s", CONVERTED);
		else if (debug_code == 6)
			ft_printf("%s", EMPTY_ARG);
		else if (debug_code == 7)
			ft_printf("DEBUG : %i argument(s) passed\n", argc - 1);
		else if (debug_code == 8)
			ft_printf("DEBUG : the %i processed numbers are valid\n", argc -1);
	}
}
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
// =========================================================================
// --------------------------- debug_print_stack ---------------------------
// =========================================================================

/**
	debug_print_stack - Displays content and metadata of a stack

	@note This function prints each node's internal values in a structured 
	format: value, index, chunk, and position. Only active in DEBUG_MODE.

	@param stack A pointer to the first node of the stack to print.
	@param c A character label to identify which stack is printed (A or B).

	@return This function does not return a value.
*/
void	debug_print_stack(t_stack *stack, char c)
{
	t_stack	*current_node;

	if (DEBUG_MODE == 1)
	{
		current_node = stack;
		ft_printf("\n-------- stack %c --------\n", c);
		while (current_node != NULL)
		{
			ft_printf("Value : %d\t\t\t", current_node->value);
			ft_printf("Index : %d\t\t\t", current_node->index);
			ft_printf("Chunk : %d\t\t\t", current_node->chunk);
			ft_printf("Position : %d\n", current_node->position);
			current_node = current_node->next;
		}
	}
}
