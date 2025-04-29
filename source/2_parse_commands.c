/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parse_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:34:19 by doberes           #+#    #+#             */
/*   Updated: 2025/04/29 15:32:59 by doberes          ###   ########.fr       */
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
/*

void parse_command(t_pipex *pipex)
{
	if (is_empty_string(pipex->cmd1->raw_cmd) == 1 
		|| is_empty_string(pipex->cmd2->raw_cmd) == 1)
		error("Command is empty");
	
}
*/

void	find_binary_path(t_cmd *cmd, char **envp)
{
	/* ETAPE 1 -> obtenir un tableau de repertoires (split)
	1. Obtenir la variable PATH de l'environnement
   - path_var = getenv("PATH");

	2. Vérifier si PATH est valide (non nul)
   - si path_var == NULL, afficher erreur et quitter;

	3. Faire un split de path_var avec ':' comme séparateur
   - path_dirs = split(path_var, ':');
   - vérifier si path_dirs contient des répertoires valides (non vides);

	4. Pour chaque répertoire dans path_dirs :
   - créer le chemin complet en combinant le répertoire et le nom de la commande (cmd_path = directory + "/" + cmd);
   - vérifier si le fichier existe à l'aide de access(cmd_path, F_OK);
   - si cmd_path existe, retourner ce chemin.

	5. Libérer la mémoire allouée pour path_dirs après utilisation (si applicable).
	*/
	/* ETAPE 2 -> chercher l'executable dans en combinant path et args[0] (strjoin)
		1. pour chaque repertoire joindre PATH et args[0] => "/bin/ls"
		2. avec access verifier si le fichier existe et executable (X_OK
		3. sinon error command is not found
		3. si chemin trouve, mettre a jour pipex->cmd->path
		4. liberer le tableau contenant des chemins testes
	*/
}

// =========================================================================
// ---------------------------- parse_command ------------------------------
// =========================================================================
static void parse_command(t_cmd *cmd, char **envp)
{
	if (is_empty_string(cmd->raw_cmd) == 1)
		error("Empty command");
	cmd->args = ft_split(cmd->raw_cmd, ' ');
	if (cmd->args == NULL || cmd->args[0] == NULL)
		error("Failed to parse command");
	cmd->path = find_binary_path(cmd, envp);
	if (cmd->path == NULL)
		error("Command not found in PATH");
	cmd->is_valid = 1;
}

// =========================================================================
// --------------------------- parse_commands ------------------------------
// =========================================================================
void parse_commands(t_pipex *pipex)
{
	parse_command(pipex->cmd1, pipex->envp);
	parse_command(pipex->cmd2, pipex->envp);
}

/*
char *find_binary_path(char *cmd) {
    char *path_var;
    char **path_dirs;
    char *cmd_path;
    char *final_path;
    int i = 0;

    // 1. Récupérer la variable d'environnement PATH
    path_var = getenv("PATH");
    if (path_var == NULL) {
        fprintf(stderr, "Error: PATH environment variable is not set.\n");
        return NULL;
    }

    // 2. Découper PATH en répertoires
    path_dirs = malloc(sizeof(char *) * (count_words(path_var) + 1)); // count_words doit compter les répertoires dans PATH
    if (path_dirs == NULL) {
        perror("Malloc failed");
        return NULL;
    }

    // Découper PATH en répertoires avec strtok
    char *token = strtok(path_var, ":");
    while (token != NULL) {
        path_dirs[i++] = token;
        token = strtok(NULL, ":");
    }
    path_dirs[i] = NULL;

    // 3. Rechercher dans chaque répertoire
    for (i = 0; path_dirs[i] != NULL; i++) {
        // Créer le chemin complet à tester
        cmd_path = strjoin(path_dirs[i], "/");
        if (cmd_path == NULL) {
            free(path_dirs);
            return NULL;
        }

        final_path = strjoin(cmd_path, cmd);
        free(cmd_path); // Libérer cmd_path après usage

        if (final_path == NULL) {
            free(path_dirs);
            return NULL;
        }

        // 4. Vérifier si le fichier existe
        if (access(final_path, F_OK | X_OK) == 0) {  // F_OK pour existence et X_OK pour exécution
            free(path_dirs);  // Libérer le tableau de chemins
            return final_path;  // Retourner le chemin trouvé
        }

        free(final_path);  // Libérer si le fichier n'est pas trouvé dans ce répertoire
    }

    // 5. Libérer la mémoire et retourner NULL si non trouvé
    free(path_dirs);
    return NULL; // Aucun fichier trouvé
}

// Utilisation de la fonction dans le processus enfant
void execute_child(t_pipex *pipex) {
    // Trouver le chemin de l'exécutable pour cmd1
    char *cmd_path = find_binary_path(pipex->cmd1->raw_cmd);
    if (cmd_path == NULL) {
        error("Command not found.");
    }

    // Mettre à jour pipex->cmd1->path avec le chemin trouvé
    pipex->cmd1->path = cmd_path;

    // Maintenant, tu peux exécuter le programme avec execve
    if (execve(pipex->cmd1->path, pipex->cmd1->args, pipex->envp) == -1) {
        error("execve failed for cmd1");
    }

    // Si execve échoue, c'est qu'il y a un problème
    free(cmd_path); // Libérer le chemin si execve échoue
}

*/