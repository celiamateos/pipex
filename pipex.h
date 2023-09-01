/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:17:05 by cmateos-          #+#    #+#             */
/*   Updated: 2023/08/02 14:17:06 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/wait.h>
# include "./libft/libft.h"
#include <errno.h>

int main (int argc, char **argv, char**envp);
char *find_path(char *cmd, char **envp);
void    execute(char *cmd, char **envp);
void    ft_error(int n);
void ft_check_args(char **argv, char **envp);
# endif

