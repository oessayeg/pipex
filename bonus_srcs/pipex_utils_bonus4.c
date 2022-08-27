/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:40:43 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/13 12:28:02 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	exec_multiple_pipes(char **argv, int argc, char **env)
{
	int	i;

	i = 2;
	while (i < argc - 1)
	{
		if (i == 2)
			first_child(argv, env);
		else if (i + 1 == argc - 1)
			final_child(argv, env, argc);
		else
			middle_child(argv, env, i);
		i++;
	}
	while (wait(NULL) != -1)
	{
	}
}

void	first_child(char **argv, char **env)
{
	int	fd[2];
	int	f_file;

	pipe(fd);
	if (fork() == 0)
	{
		f_file = open(argv[1], O_RDONLY);
		if (f_file < 0)
		{
			perror(argv[1]);
			exit(errno);
		}
		if (check_ph(argv[2]) == 0 || command_check(argv[2], env) == 0)
		{
			close(fd[1]);
			exit(errno);
		}
		close(fd[0]);
		dup2(f_file, 0);
		dup2(fd[1], 1);
		exec(env, argv[2]);
		exit(errno);
	}
	else
		dup2(fd[0], 0);
}

void	middle_child(char **argv, char **env, int i)
{
	int	fd[2];

	pipe(fd);
	if (fork() == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (check_ph(argv[i]) == 0 || command_check(argv[i], env) == 0)
		{
			close(fd[1]);
			exit(errno);
		}
		exec(env, argv[i]);
		exit(errno);
	}
	else
		dup2(fd[0], 0);
}

void	final_child(char **argv, char **env, int argc)
{
	int	f_out;

	if (fork() == 0)
	{
		f_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (f_out < 0)
		{
			perror(argv[argc - 1]);
			exit(errno);
		}
		if (check_ph(argv[argc - 2]) == 0 || command_check(argv[argc - 2], env) == 0)
			exit(errno);
		dup2(f_out, 1);
		exec(env, argv[argc - 2]);
	}
}

int	check_ph(char *command)
{
	char	**comm_split;
	int	i;

	i = -1;
	while (command[++i] == ' ');
	while (command[i] && command[i] != ' ')
	{
		if (command[i] == '/')
		{
			comm_split = ft_split(command, ' ');
			if (access(comm_split[0], F_OK) != 0
				|| access(comm_split[0], X_OK) != 0)
			{
				perror(comm_split[0]);
				free_all(comm_split);
				return (0);
			}
				free_all(comm_split);
		}
		i++;
	}
	return (1);
}
