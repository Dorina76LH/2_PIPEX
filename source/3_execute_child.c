/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_execute_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:59:05 by doberes           #+#    #+#             */
/*   Updated: 2025/04/25 17:16:49 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// -------------------------- execute_child1_write -------------------------
// =========================================================================
// lit depuis infile et ecrit dans le pipe (pipe_fd[1])
void	execute_child1_write(char **argv, char **envp, int *pipe_fd)
{
	int infile = open(argv[1], O_RDONLY);
	if (infile < 0)
    	error("Failed to open infile");

	dup2(infile, STDIN_FILENO);     // rediriger l'entrée standard
	dup2(pipe_fd[1], STDOUT_FILENO); // rediriger la sortie vers pipe
	close_pipes(pipe_fd);

	char **cmd_args = parse_arguments(argv[2]);
	char *cmd_path = find_binary_path(cmd_args[0], envp);
	execve(cmd_path, cmd_args, envp);
	error("execve failed");
}

// =========================================================================
// -------------------------- execute_child2_read --------------------------
// =========================================================================
// Lit depuis le pipe (pipe_fd[0]) et ecrit dans outfile
void	execute_child2_read(char **argv, char **envp, int *pipe_fd)
{
	int outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error("Failed to open outfile");

	dup2(pipe_fd[0], STDIN_FILENO); // lire depuis pipe
	dup2(outfile, STDOUT_FILENO);   // écrire vers outfile
	close_pipes(pipe_fd);

	char **cmd_args = parse_arguments(argv[3]);
	char *cmd_path = find_binary_path(cmd_args[0], envp);
	execve(cmd_path, cmd_args, envp);
	error("execve failed");
}
