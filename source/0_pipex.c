/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:18:21 by doberes           #+#    #+#             */
/*   Updated: 2025/04/24 15:18:29 by doberes          ###   ########.fr       */
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

    @return Returns 0 if the program runs successfully, otherwise exits 
            with an error.
*/
int	main(int argc, char *argv[], char **envp)
{
	(void)	argc;
	(void)	argv;
    int     fd;
    char    *args[] = {"ls", "-l", NULL};

    fd = open("exemple.txt", O_WRONLY | O_CREAT, 0644);
    dup2(fd, STDOUT_FILENO);
    close(fd);

    if (access("exemple.txt", R_OK) == 0)
        ft_printf("I have permission\n");
    else
    {
        ft_printf("I don't have permission\n");
    }
	execve("/bin/ls", args, envp);
    ft_printf("\nPipex program has been executed. \n");
	return (0);
}
