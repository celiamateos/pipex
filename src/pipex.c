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

void	child_process(char *file1, char *cmd, char **envp, int *fd)
{
	int	infile;

	infile = open(file1, O_RDONLY, 0777);
	if (infile == -1)
		ft_error();
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	execute(cmd, envp);
}

void	parent_process(char *file2, char *cmd, char **envp, int *fd)
{
	int	outfile;

	outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	(close(fd[1]), close (outfile));
	execute(cmd, envp);
}

void	leaks(void)
{
	system ("leaks -q pipex");
}

int	main(int argc, char **argv, char**envp)
{
	//atexit(leaks);
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if ((!*envp && argv[2][0] != '/' && argv[3][0] != '/')
		|| argv[1][0] == '\0' || argv[2][0] == '\0'
		|| argv[3][0] == '\0' || argv[1][0] == '\0'
		|| argv[2][0] == '\0' || argv[3][0] == '\0'
		|| access(argv[1], R_OK) == -1)
			ft_error();
		if (pipe(fd) == -1)
			ft_error();
		pid = fork();
		if (pid == 0)
			child_process(argv[1], argv[2], envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv[4], argv[3], envp, fd);
	}
	else
	{
		ft_putstr_fd("Error\n Invalid argv", 2);
		ft_putstr_fd("Ex:./pipex infile cmd1 cmd2 outfile", 2);
	}
	return (0);
}
