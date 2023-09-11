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

void	child1_process(char *file1, char *cmd, char **envp, int *fd)
{
	int	infile;

	if (access(file1, F_OK) == -1)
		ft_error(4, file1);
	infile = open(file1, O_RDONLY, 0777);
	if (infile == -1)
		ft_error(3, file1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	if (execute(cmd, envp))
		ft_error(0, NULL);
}

void	child2_process(char *file2, char *cmd, char **envp, int *fd)
{
	int	outfile;

	outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error(0, file2);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	(close(fd[1]), close (outfile));
	if (execute(cmd, envp))
		ft_error(0, NULL);
}

static void	ft_wait_process(int *fd, int pid1, int pid2)
{
	int	status;

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		if (status != EXIT_SUCCESS)
			ft_error(0, NULL);
	}
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		if (status != EXIT_SUCCESS)
			ft_error(0, NULL);
	}
}

int	main(int argc, char **argv, char**envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc == 5)
	{
		ft_check_args(argv, envp);
		if (pipe(fd) == -1)
			ft_error(0, NULL);
		pid1 = fork();
		if (pid1 == 0)
			child1_process(argv[1], argv[2], envp, fd);
		if (pid1 > 0)
		{
			pid2 = fork();
			if (pid2 == 0)
				child2_process(argv[4], argv[3], envp, fd);
			if (pid2 > 0)
				ft_wait_process(fd, pid1, pid2);
		}
	}
	else
		ft_putstr_fd("Error\n Invalid arguments", 2);
	return (0);
}
