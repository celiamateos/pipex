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
        if (access(path, F_OK) == 0) {
            ft_putstr_fd(path, 2);
            return (path); }
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

    if (cmd[0] == '/')
    {
        simple_cmd = ft_split(cmd, '/');
        if (access(cmd, F_OK) == 0)
        {
            if (execve(cmd, simple_cmd, envp) == -1)
                perror("Error 2");
            //execve solamente deja pasar ** como 2o arg.
        }

    }
    else {
    simple_cmd = ft_split(cmd, ' ');
    path = find_path(simple_cmd[0], envp);
    if(execve(path, simple_cmd, envp) == -1)
        perror("Error"); }
    i = -1;
    while (simple_cmd[++i])
        free(simple_cmd[i]);
    free (simple_cmd);
    free (path);
}
