/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_msg_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:40:49 by doberes           #+#    #+#             */
/*   Updated: 2025/04/25 17:17:58 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// --------------------------------- error ---------------------------------
// =========================================================================
int	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

// =========================================================================
// ------------------------------ close_pipe -------------------------------
// =========================================================================
void	close_pipe(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
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

void init_pipex(t_pipex *pipex, char **argv, char **envp)
{
    pipex->envp = envp;

    pipex->infile_fd = open(argv[1], O_RDONLY);
    if (pipex->infile_fd < 0)
        error_exit("Failed to open infile");

    pipex->outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (pipex->outfile_fd < 0)
        error_exit("Failed to open outfile");

    if (pipe(pipex->pipe_fd) == -1)
        error_exit("Failed to create pipe");

    pipex->cmd1_args = parse_arguments(argv[2]);
    pipex->cmd2_args = parse_arguments(argv[3]);

    pipex->cmd1_path = find_binary_path(pipex->cmd1_args[0], envp);
    pipex->cmd2_path = find_binary_path(pipex->cmd2_args[0], envp);

    if (!pipex->cmd1_path || !pipex->cmd2_path)
        error_exit("Command not found");
}
