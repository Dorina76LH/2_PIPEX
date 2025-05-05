/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:34:19 by doberes           #+#    #+#             */
/*   Updated: 2025/05/05 16:17:48 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// ---------------------------- is_whitespace ------------------------------
// =========================================================================
/**
 	is_whitespace - Check if a character is a whitespace character.

	@param c The character to check.

	@return 1 if the character is a whitespace, 0 otherwise.
 */

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

// =========================================================================
// --------------------------- is_empty_string -----------------------------
// =========================================================================
/**
	is_empty_string - Check if a string is empty or contains only whitespace
					  characters.

	@param str The string to check.

	@return 1 if the string is empty or contains only whitespace, 0 otherwise.
 */
int	is_empty_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (is_whitespace(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// =========================================================================
// ------------------------ build_executable_path --------------------------
// =========================================================================

static char	*build_path(char *dir, char *cmd_name, t_pipex *pipex)
{
	char	*path;
	char	*tmp;

	if (!dir || !cmd_name)
		exit_with_cleanup("Invalide directory or command name", 0, pipex);
	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		exit_with_cleanup("Memory allocation failed", 0, pipex);
	path = ft_strjoin(tmp, cmd_name);
	free(tmp);
	if (!path)
		exit_with_cleanup("Memory allocation failed", 0, pipex);
	return (path);
}
// =========================================================================
// --------------------------- find_binary_path ----------------------------
// =========================================================================

/**
 * find_binary_path - Searches the PATH directories to locate the executable.
 *
 * This function builds possible full paths by joining each directory from
 * the PATH variable with the command name. It checks if the executable exists
 * and is accessible. If found, the binary path is stored in the command struct.
 *
 * @pipex: Holds the environment variable PATH.
 * @cmd: The command structure containing the parsed arguments.
 */

void	find_binary_path(t_pipex *pipex, t_cmd	*cmd)
{
	char	**dirs;
	char	*current_binary;
	int		i;

	dirs = ft_split(pipex->path, ':');
	if (!dirs)
		exit_with_cleanup("Memory allocation failed", 0, pipex);
	i = 0;
	while (dirs[i])
	{
		current_binary = build_path(dirs[i], cmd->parsed_args[0], pipex);
		if (access(current_binary, X_OK) == 0)
		{
			free_str_array(dirs);
			cmd->binary_path = current_binary;
			cmd->is_valid = 1;
			return ;
		}
		free(current_binary);
		i++;
	}
	// close infile outfile
	free_str_array(dirs);
	exit_with_cleanup("Command is not exist", 0, pipex);
}

// =========================================================================
// ---------------------------- parse_command ------------------------------
// =========================================================================
void	parse_command(t_cmd *cmd, t_pipex *pipex)
{
	if (is_empty_string(cmd->input_cmd_str) == 1)
		exit_with_cleanup("Empty command", 0, pipex);
	cmd->parsed_args = ft_split(cmd->input_cmd_str, ' ');
	if (cmd->parsed_args == NULL)
		exit_with_cleanup("Memory allocation failed", 0, pipex);
	if (cmd->parsed_args == NULL || cmd->parsed_args[0][0] == '\0')
		exit_with_cleanup("Command not found", 0, pipex);
	find_binary_path(pipex, cmd);
	return ;
}
