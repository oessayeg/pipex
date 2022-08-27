/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:37:53 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/13 11:45:44 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];

	arg_check(argc);
	if (pipe(fd) == -1)
		error_message("pipe");
	child_process1(argv, env, fd);
	child_process2(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

int	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (0);
	}
	close(fd);
	return (1);
}

int	is_in(char *command)
{
	int	i;

	i = -1;
	while (command[++i])
		if (command[i] == '/')
			return (1);
	return (0);
}

int	check_ph(char *command)
{
	char	**comm_split;
	
	if (is_in(command))
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
	return (1);
}
