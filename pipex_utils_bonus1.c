/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:20:39 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/13 12:24:13 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	exec_here_doc(char **argv, char **env)
{
	int		fd[2];
	char	*string;
	int		fd_doc[2];

	string = read_from_input(argv[2]);
	if (pipe(fd) == -1 || pipe(fd_doc) == -1)
		error_message("pipe");
	if (string != NULL)
		ft_putstr_fd(string, fd_doc[1]);
	free(string);
	here_doc_child1(argv, env, fd, fd_doc);
	close(fd_doc[0]);
	close(fd_doc[1]);
	here_doc_child2(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

void	here_doc_child1(char **argv, char **env, int *fd, int *h_fd)
{
	if (fork() == 0)
	{
		close(fd[0]);
		close(h_fd[1]);
		if (command_check(argv[3], env) == 0)
		{
			close(fd[1]);
			close(h_fd[0]);
			exit(errno);
		}
		dup2(h_fd[0], 0);
		dup2(fd[1], 1);
		exec(env, argv[3]);
		exit(errno);
	}
}

void	here_doc_child2(char **argv, char **env, int *fd)
{
	int	fd_f;

	if (fork() == 0)
	{
		close(fd[1]);
		fd_f = open(argv[5], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd_f < 0)
		{
			close(fd[0]);
			error_message(argv[5]);
		}
		if (command_check(argv[4], env) == 0)
		{
			close(fd[0]);
			exit(errno);
		}
		dup2(fd[0], 0);
		dup2(fd_f, 1);
		exec(env, argv[4]);
		exit(errno);
	}
}

int	command_check(char *command, char **env)
{
	char	*command_path;
	char	**paths;
	char	*real_command;

	if (no_command(command) == 0)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found\n", 2);
		return (0);
	}
	if (check_path(give_me_command(command, 2)) == 1)
		return (1);
	paths = ft_split(find_path(env), ':');
	real_command = give_me_command(command, 1);
	command_path = path_please(paths, real_command);
	if (command_path == NULL)
	{
		ft_putstr_fd(&real_command[1], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_everything(paths, real_command, command_path);
		return (0);
	}
	free_everything(paths, real_command, command_path);
	return (1);
}

int	len_to_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (i);
}
