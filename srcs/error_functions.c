/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:38:37 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/13 11:44:58 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	arg_check(int args)
{
	if (!(args == 5))
	{
		ft_putstr_fd("Bad arguments\n", 2);
		ft_putstr_fd("--> ./pipex <infile> 'cmd1' 'cmd2' <outfile>\n", 2);
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

void	free_everything(char **to_free1, char *to_free2, char *to_free3)
{
	int	i;

	free(to_free2);
	free(to_free3);
	i = 0;
	while (to_free1[i])
	{
		free(to_free1[i]);
		i++;
	}
	free(to_free1);
}

int	check_path(char *command)
{
	if (access(command, X_OK) == 0)
	{
		free(command);
		return (1);
	}
	free(command);
	return (0);
}
