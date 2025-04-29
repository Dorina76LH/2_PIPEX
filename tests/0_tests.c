/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_tests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:34:25 by doberes           #+#    #+#             */
/*   Updated: 2025/04/29 12:54:56 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "../include/pipex.h"

// =========================================================================
// --------------------------------- main ----------------------------------
// =========================================================================
int	main(void)
{
	ft_printf("\nAll tests have been executed.\n\n");
	return (0);
}

/*
🔹 1. Tester init_pipex() seule
But : vérifier que les fichiers sont bien ouverts, le pipe bien créé, les
arguments bien parsés.

Ajoute dans main() juste après l’appel à init_pipex :

printf("infile_fd: %d\n", pipex.infile_fd);
printf("outfile_fd: %d\n", pipex.outfile_fd);
printf("cmd1: %s\n", pipex.cmd1_args[0]);
printf("cmd1_path: %s\n", pipex.cmd1_path);
printf("cmd2: %s\n", pipex.cmd2_args[0]);
printf("cmd2_path: %s\n", pipex.cmd2_path);
Ensuite tu lances :

./pipex infile "ls -l" "wc -l" outfile

2. Tester parse_arguments() séparément
Crée un petit test.c à part (hors pipex.c) :

int main(void)
{
    char **args = parse_arguments("grep hello");

    for (int i = 0; args[i]; i++)
        printf("arg[%d] = %s\n", i, args[i]);

    // free args à la fin
    return (0);
}
Compile juste ça avec gcc test.c utils.c (en adaptant selon tes fichiers).

🔹 3. Tester find_binary_path()
Pareil : dans un mini main() de test :

int main(int argc, char **argv, char **envp)
{
    char *path = find_binary_path("ls", envp);
    printf("Path: %s\n", path);
    return (0);
}
🔹 4. Tester les enfants (cmd1/cmd2)
Une fois que init_pipex() est fiable, tu peux tester les forks et execve :

if ((pipex.pid1 = fork()) == 0)
    execute_child1_write(&pipex, argv); // test uniquement ça au début
Dans cette fonction, commence simple :

dup2(pipex.infile_fd, STDIN_FILENO);
dup2(pipex.pipe_fd[1], STDOUT_FILENO);
close_pipes(pipex.pipe_fd);

execve(pipex.cmd1_path, pipex.cmd1_args, pipex.envp);
perror("execve failed");
exit(1);
Si ton cmd1 s’exécute bien, c’est que execve, dup2, args, etc. sont bien gérés.

🛠 Conseil : tester avec des commandes simples
Quand tu testes, utilise :

./pipex infile "cat" "wc -l" outfile
Tu peux même commencer par écrire en dur "ls" ou "cat" dans ton init_pipex() pour
isoler le problème de parsing/exec.


*/