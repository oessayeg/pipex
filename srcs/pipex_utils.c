/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:41:23 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/13 11:45:40 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	error_message(char *string)
{
	perror(string);
	exit(errno);
}

void	child_process1(char **argv, char **env, int *fd)
{
	int	file;

	if (fork() == 0)
	{
		close(fd[0]);
		if (check_file(argv[1]) == 0 || check_ph(argv[2]) == 0
			|| command_check(argv[2], env) == 0)
		{
			close(fd[1]);
			exit(errno);
		}
		file = open(argv[1], O_RDONLY);
		dup2(file, 0);
		dup2(fd[1], 1);
		exec(env, argv[2]);
		exit(errno);
	}
}

void	child_process2(char **argv, char **env, int *fd)
{
	int	file;

	if (fork() == 0)
	{
		close(fd[1]);
		file = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (file < 0)
		{
			close(fd[0]);
			error_message(argv[4]);
		}
		else if (check_ph(argv[3]) == 0 || command_check(argv[3], env) == 0)
		{
			close(fd[0]);
			exit(errno);
		}
		dup2(fd[0], 0);
		dup2(file, 1);
		exec(env, argv[3]);
		exit(errno);
	}
}

void	exec(char **env, char *command)
{
	char	**dp_command;
	char	*path_to_command;
	char	**paths;

	dp_command = ft_split(command, ' ');
	if (check_path(dp_command[0]) == 1)
	{
		execve(dp_command[0], dp_command, env);
		perror(dp_command[0]);
		exit(errno);
	}
	paths = ft_split(find_path(env), ':');
	path_to_command = path_please(paths, give_me_command(command, 1));
	free_all(paths);
	execve(path_to_command, dp_command, env);
}

void	free_all(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i] != NULL)
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}
