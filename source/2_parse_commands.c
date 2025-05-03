/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parse_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:34:19 by doberes           #+#    #+#             */
/*   Updated: 2025/05/02 16:50:11 by doberes          ###   ########.fr       */
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
	if (str == NULL || str[i] == '\0')
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

static char	*build_executable_path(char *dir, char *cmd_name)
{
	char	*path;
	char	*tmp;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		error("Memory allocation failed");
	path = ft_strjoin(tmp, cmd_name);
	free(tmp);
	if (!path)
		error("Memory allocation failed");
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

	dirs = ft_split(pipex->envp, ':');
	if (!dirs)
		error("Memory allocation failed");
	i = 0;
	while (dirs[i])
	{
		current_binary = build_executable_path(dirs[i], cmd->parsed_args[0]);
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
	free_str_array(dirs);
	error("Command is not found");
}

// =========================================================================
// ---------------------------- parse_command ------------------------------
// =========================================================================
void	parse_command(t_cmd *cmd, t_pipex *pipex)
{
	if (is_empty_string(cmd->input_cmd_str) == 1)
		error("Empty command");
	cmd->parsed_args = ft_split(cmd->input_cmd_str, ' ');
	if (cmd->parsed_args == NULL || cmd->parsed_args[0] == NULL)
		error("Failed to parse command");
	find_binary_path(pipex, cmd);
	return ;
}


void	find_binary_path(t_pipex *pipex, t_cmd *cmd)
{
	char	**dirs;
	char	*bin;
	int		i;

	dirs = ft_split(pipex->envp, ':');
	if (!dirs)
		error("Memory allocation failed");
	i = 0;
	while (dirs[i])
	{
		bin = build_executable_path(dirs[i], cmd->parsed_args[0]);
		if (access(bin, X_OK) == 0)
		{
			free_str_array(dirs);
			cmd->binary_path = bin;
			cmd->is_valid = 1;
			return ;
		}
		free(bin);
		i++;
	}
	free_str_array(dirs);
	error("Command is not found");
}

/*
	void	find_binary_path(t_pipex *pipex, t_cmd	*cmd)
{
	char	**envp_path_dirs;
	char	*current_directory;
	char	*current_binary;
	int		i;

	envp_path_dirs = ft_split(pipex->envp, ':');
	if (!envp_path_dirs)
		error("Memory allocation failed");
	i = 0;
	while (envp_path_dirs[i])
	{
		current_directory = ft_strjoin(envp_path_dirs[i], "/");
		if (!current_directory)
			error("Memory allocation failed");
		current_binary = ft_strjoin(current_directory, cmd->parsed_args[0]);
		free(current_directory);
		if (!current_binary)
			error("Memory allocation failed");
		if (access(current_binary, X_OK) == 0)
		{
			free_str_array(envp_path_dirs);
			cmd->binary_path = current_binary;
			return ;
		}
		free(current_binary);
		i++;
	}
	free_str_array(envp_path_dirs);
	error("Command is not found");
}
*/

/*
int i = 0;
while (dirs[i])
{
    current_binary = build_executable_path(dirs[i], cmd->parsed_args[0]);
    if (access(current_binary, X_OK) == 0)
    {
        cmd->binary_path = current_binary;
        cmd->is_valid = 1;
        break;
    }
    free(current_binary);
    i++;
}

if (!dirs[i]) {
    free_str_array(dirs);
    error("Command is not found");
}
free_str_array(dirs);

*/