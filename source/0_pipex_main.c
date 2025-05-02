/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_pipex_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:18:21 by doberes           #+#    #+#             */
/*   Updated: 2025/05/02 16:28:26 by doberes          ###   ########.fr       */
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
/*
**  @todo Quelques suggestions d'amélioration :
Erreur execve: Actuellement, tu appelles error("execve failed") juste après
un appel à execve. Cela peut être un peu déroutant si jamais execve échoue, car
il ne renvoie jamais si tout se passe bien. Peut-être que tu pourrais utiliser
perror avec un message plus précis, comme perror("execve failed for command")
avant de sortir du programme.

Gestion de la fermeture des descripteurs de fichiers dans close_pipes:
Assure-toi que close_pipes fait bien son travail, notamment la fermeture des
descripteurs de fichiers. C'est une bonne pratique de toujours fermer les
descripteurs de fichiers une fois qu'ils ne sont plus utilisés.

Peut-être éviter le dup2 multiple : Dans tes fonctions d'exécution des enfants,
tu utilises dup2 deux fois pour rediriger les flux de STDIN et STDOUT. C'est
correct, mais tu pourrais envisager de les encapsuler dans une fonction
utilitaire pour rendre le code encore plus lisible et éviter la répétition de
code si tu as d'autres redirections à gérer.
** 
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
	// declaration des variables
	t_pipex	pipex;

	// controle des arguments
	if (argc != 5)
		error("Usage : ./pipex infile cmd1 cmd2 outfile\n");
	// initialiser la structure pipex
	pipex = init_pipex(argv, envp);
	// parsing des commandes
	//parse_command(pipex->cmd1, pipex->envp);
	//parse_command(pipex->cmd2, pipex->envp);
	// parse_commands(argv, &pipex);
	// creer le pipe
	create_pipe(&pipex);
	// fork les enfants
	create_children(&pipex);
	// fermer les pipes dans le parent
	close_unused_fds_at_start(&pipex, PARENT);
	// executer les processus enfant
	execute_children(&pipex);
	// attendre la fin des enfants
	wait_for_children(&pipex);
	// liberer les fds utilises
	close_opened_fds_at_end(&pipex, PARENT);
	// liberer la memoire pour les structures cmd1 et cmd2
	free_memory(&pipex);
	return (EXIT_SUCCESS);
}

	// si tu utilises des fichiers temporaires, pense à unlink
	// unlink(temp_file)

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

/*
pipex.envp = envp;
pipex.infile_fd = open(argv[1], O_RDONLY);
pipex.outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
pipex.cmd1_args = parse_arguments(argv[2]);
pipex.cmd2_args = parse_arguments(argv[3]);

pipex.cmd1_path = find_binary_path(pipex.cmd1_args[0], envp);
pipex.cmd2_path = find_binary_path(pipex.cmd2_args[0], envp);
*/
/*
void	init_data(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd1->cmd1_args = parse_arguments(argv[2]);
	pipex->cmd2->cmd2_args = parse_arguments(argv[3]);

	pipex->cmd1->cmd1_path = find_binary_path(pipex->cmd1->cmd1_args[0], envp);
	pipex->cmd2->cmd2_path = find_binary_path(pipex->cmd2->cmd2_args[0], envp);

	if (!pipex->cmd1->cmd1_path || !pipex->cmd2->cmd2_path)
		error_exit("Command not found");
}
*/


// save main
/*
int	main(int argc, char **argv, char **envp)
{
	// declaration des variables
	t_pipex	pipex;

	// controle des arguments
	if (argc != 5)
		return(error("Usage : ./pipex infile cmd1 cmd2 outfile\n"));
	
	// initialiser la structure pipex
	pipex = init_pipex(argv, envp);
	
	// creer le pipe
	if (pipe(pipex.pipe_fd) == -1)
		return(error("Pipe() failed"));
	
	// lancer le premier enfant (cmd1)
	// valeur de retour fork() == 0, je suis dans le processus enfant
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		execute_child1_write(argv, pipex.envp, pipex.pipe_fd);
	
	// lancer le deuxieme enfant (cmd2)
	// valeur de retour fork() == 0, je suis dans le processus enfant
	if (pipex.pid2 == 0)
		execute_child2_read(argv, pipex.envp, pipex.pipe_fd);
	
	// fermer les pipes dans le parent
	close_pipe(pipex.pipe_fd);

	// attendre la fin des enfants
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);

	// liberer la memoire pour les structures cmd1 et cmd2
	free_memory(&pipex);
	// voir aussi unlink ?
	return (0);
}
*/
