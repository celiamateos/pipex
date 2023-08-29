/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:14:20 by cmateos-          #+#    #+#             */
/*   Updated: 2023/08/02 14:14:23 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

char *find_path(char *cmd, char **envp)
{
    int i;
    char *path;
    char *path2;
    char **posibles_path;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == NULL)
        i++; 
    posibles_path = ft_split(envp[i] + 5, ':');
    i = -1;
    while (posibles_path[++i])
    {
        path2 = ft_strjoin(posibles_path[i], "/");
        free(posibles_path[i]);
        path = ft_strjoin(path2, cmd);
        free (path2);
        if (access(path, F_OK) == 0)
            return (path);
        free(path);
    }
    free(posibles_path);
    return NULL;
}

void    execute(char *cmd, char **envp)
{
    char **simple_cmd;
    char *path;
    int     i;

    simple_cmd = ft_split(cmd, ' ');
    path = find_path(simple_cmd[0], envp);
    if(execve(path, simple_cmd, envp) == -1)
        perror("Error");
    i = -1;
    while (simple_cmd[++i])
        free(simple_cmd[i]);
    free (simple_cmd);
    free (path);
}

void    child_process(char *file1, char *cmd, char **envp, int *fd)
{
    int infile;

    infile = open(file1, O_RDONLY, 0777);
    if (infile == -1)
        perror("Error\n");
    dup2(infile, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    execute(cmd, envp);
    
}

void    parent_process(char *file2, char *cmd, char **envp, int *fd)
{
    int outfile;

    outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (outfile == -1)
        perror("Error");
    dup2(fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    close(fd[1]);
    execute(cmd, envp);
}

int main (int argc, char **argv, char**envp)
{
    int     fd[2];
    pid_t   pid;

    if (argv[1][0] == '\0' || argv[2][0] == '\0'
    || argv[3][0] == '\0')
        return 0;
    if (argc == 5)
    {
        if (pipe(fd) == -1)
            perror("Error\n");
        pid = fork();
        if (pid == 0)
            child_process(argv[1], argv[2], envp, fd);
        waitpid(pid, NULL, 0);
        parent_process(argv[4], argv[3], envp, fd);
    }
    return 0;
}

/*int main (int argc, char **argv, char**envp)
{
    int fd[2];
    pid_t pid;

    if (argc == 5)
	{
		if (pipe(fd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
}*/


/*int main(void)
{
    int fd[2];
    int result = pipe(fd);

    if (result == -1) 
    {
        perror("Error al crear la tubería");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Error al crear el proceso hijo");
        return 1;
    }
    else if (pid == 0) {
        // Proceso hijo
        close(fd[1]); // Cerramos el descriptor de escritura, ya que no lo necesitamos en el proceso hijo
        char buffer[1024];
        int num_bytes = read(fd[0], buffer, sizeof(buffer));
        printf("Proceso hijo: Recibidos %d bytes: %.*s\n", num_bytes, num_bytes, buffer);
        close(fd[0]); // Cerramos el descriptor de lectura una vez que hemos terminado de usarlo
    }
    else
    {
        // Proceso padre
        close(fd[0]); // Cerramos el descriptor de lectura, ya que no lo necesitamos en el proceso padre
        char mensaje[] = "Hola, proceso hijo!";
        write(fd[1], mensaje, sizeof(mensaje));
        close(fd[1]); // Cerramos el descriptor de escritura una vez que hemos terminado de usarlo
    }

    return 0;
}*/

