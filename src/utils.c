/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:38:45 by cmateos           #+#    #+#             */
/*   Updated: 2023/08/31 15:38:47 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_error(int n, char *cmd)
{
	if (n == 0)
	{
		ft_putstr_fd(strerror(errno), 2);
	}
	if (n == 1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmd, 2);
	}
	if (n == 3)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putstr_fd(cmd, 2);
	}
	if (n == 4)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(cmd, 2);
	}
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_check_args(char **argv, char **envp)
{
	if ((!*envp) && (argv[2][0] != '/' || argv[3][0] != '/'))
		ft_error(0, NULL);
	if (argv[1][0] == '\0')
		ft_error(4, argv[1]);
	if (argv[4][0] == '\0')
		ft_error(4, argv[4]);
	if (argv[2][0] == '\0')
		ft_error(3, argv[2]);
	if (argv[3][0] == '\0')
		ft_error(3, argv[3]);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*path2;
	char	**posibles_path;

	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	if (envp[i] == NULL)
		return (NULL);
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
	return (NULL);
}

int	execute(char *cmd, char **envp)
{
	char	**simple_cmd;
	char	*path;
	int		i;
	int		ex;

	ex = -1;
	simple_cmd = ft_split(cmd, ' ');
	if (cmd[0] != '/' && cmd[0] != '.')
	{
		path = find_path(simple_cmd[0], envp);
		if (path)
			ex = execve(path, simple_cmd, envp);
		free(path);
	}
	else
		if (access(cmd, F_OK) == 0)
			ex = execve(cmd, simple_cmd, envp);
	i = -1;
	while (simple_cmd[++i])
		free(simple_cmd[i]);
	free (simple_cmd);
	if (ex < 0)
		return (ft_error(1, cmd), 1);
	return (0);
}
