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

int	child_process(char *file1, char *cmd, char **envp, int *fd)
{
	int	infile;

	infile = open(file1, O_RDONLY, 0777);
	if (infile == -1)
		ft_error(3, file1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	if (execute(cmd, envp))
		return (1);
	return (0);
}

void	parent_process(char *file2, char *cmd, char **envp, int *fd)
{
	int	outfile;

	outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error(0, file2);
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
	atexit(leaks);
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		ft_check_args(argv, envp);
		if (pipe(fd) == -1)
			ft_error(0, NULL);
		pid = fork();
		if (pid == 0)
			if (child_process(argv[1], argv[2], envp, fd))
				ft_error(0, NULL);
		parent_process(argv[4], argv[3], envp, fd);
		waitpid(-1, NULL, 0);
	}
	else
	{
		ft_putstr_fd("Error\n Invalid argv", 2);
		ft_putstr_fd("Ex:./pipex infile cmd1 cmd2 outfile", 2);
	}
	return (0);
}
