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
