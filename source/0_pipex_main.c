/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:18:21 by doberes           #+#    #+#             */
/*   Updated: 2025/04/25 17:25:34 by doberes          ###   ########.fr       */
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

*/

int	main(int argc, char **argv, char **envp)
{
	// declaration des variables
	int 	pipe_fd[2]; // pide_fd[0] = read, pipe_fd[1] = write
	pid_t	pid1;		// pid child1 = cmd1
	pid_t	pid2;		// pid child2 = cmd2
	// t_pipex	pipex; => revoir la declaration des variables

	// controle des arguments
	if (argc != 5)
		return(error("Usage : ./pipex infile cmd1 cmd2 outfile\n"));
	
	// init_pipex(&pipex, argv, envp); 
	// creer le pipe
	if (pipe(pipe_fd) == -1)
		return(error("Pipe() failed"));
	
	// lancer le premier enfant (cmd1)
	// valeur de retour fork() == 0, je suis dans le processus enfant
	pid1 = fork();
	if (pid1 == 0)
		execute_child1_write(argv, envp, pipe_fd);
	
	// lancer le deuxieme enfant (cmd2)
	// valeur de retour fork() == 0, je suis dans le processus enfant
	if (pid2 == 0)
		execute_child2_read(argv, envp, pipe_fd);
	
	// fermer les pipes dans le parent
	close_pipe(pipe_fd);

	// attendre la fin des enfants
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	// voir aussi unlink ?
	return (0);
}


char **parse_arguments(char *cmd)
{
    // Utiliser ft_split(cmd, ' ') ou similaire
    // Retourner un tableau de strings
}

char *find_binary_path(char *cmd, char **envp)
{
    // 1. Chercher la variable PATH dans envp
    // 2. Split PATH sur ':' pour obtenir les répertoires
    // 3. Tester chaque répertoire + cmd avec access(path, X_OK)
    // 4. Si trouvé, retourner le chemin complet
    // 5. Sinon, afficher une erreur
}
