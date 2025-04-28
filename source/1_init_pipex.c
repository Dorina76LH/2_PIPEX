/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:53:22 by doberes           #+#    #+#             */
/*   Updated: 2025/04/28 16:08:53 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// ------------------------------ init_pipex -------------------------------
// =========================================================================

t_pipex	init_pipex(char **argv, char **envp)
{
	t_pipex	pipex;

	init_cmd_structures(&pipex);
	handle_file_descriptors(&pipex, argv);
	pipex.envp = envp;
	pipex.cmd1->raw_cmd = argv[2];
	pipex.cmd2->raw_cmd = argv[3];
	return (pipex);
}
// =========================================================================
// ------------------------- init_cmd_structures ---------------------------
// =========================================================================

// allouer la memoire les pour les structures cmd1 et cmd2
// initialiser variables des structures cmd1 et cmd2
void	init_cmd_structures(t_pipex *pipex)
{
	pipex->cmd1 = malloc(sizeof(t_cmd));
	pipex->cmd2 = malloc(sizeof(t_cmd));
	if (pipex->cmd1 == NULL || pipex->cmd2 == NULL)
		error("Memory allocation failesd");
	pipex->cmd1->raw_cmd = NULL;
	pipex->cmd1->args = NULL;
	pipex->cmd1->path = NULL;
	pipex->cmd1->is_valid = 0;
	pipex->cmd2->raw_cmd = NULL;
	pipex->cmd2->args = NULL;
	pipex->cmd2->path = NULL;
	pipex->cmd2->is_valid = 0;
}

// =========================================================================
// ----------------------- handle_file_descriptors -------------------------
// =========================================================================
// Fonction pour rediriger les file descriptors
void	handle_file_descriptors(t_pipex *pipex, char **argv)
{
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
		error("Failed to open infile");

	pipex->outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
		error("Failed to open outfile");
}

