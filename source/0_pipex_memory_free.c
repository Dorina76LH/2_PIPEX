/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_memory_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:37 by doberes           #+#    #+#             */
/*   Updated: 2025/04/29 15:12:49 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// ------------------------------ free_args -------------------------------
// =========================================================================
// Libérer le tableau d'arguments d'une commande (cmd1 ou cmd2)
static void	free_args(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

// =========================================================================
// ------------------------------ free_memory ------------------------------
// =========================================================================
// rajouter aussi un free pour le path dans find_binary_path
/**
	free_memory - Free memory allocated for command structures.

	@note This function releases the memory allocated for the command
	structures. It should be expanded to free any dynamically allocated
	arguments inside the command structures.

	@param pipex Pointer to the main Pipex structure containing commands.

	@return None.
*/
void	free_memory(t_pipex *pipex)
{
	free_args(pipex->cmd1->args);
	free_args(pipex->cmd2->args);
	free(pipex->cmd1);
	free(pipex->cmd2);
}

/*
Libérer pipex->cmd1->path et pipex->cmd2->path si find_binary_path
l’alloue dynamiqueme
free(pipex->cmd1->path);
free(pipex->cmd2->path);
2.	Robustesse : vérifie cmd1 et cmd2 avant de les free (si jamais tu
prévois une init partielle) :
if (pipex->cmd1)
{
    free_args(pipex->cmd1->args);
    free(pipex->cmd1->path);
    free(pipex->cmd1);
}
*/
