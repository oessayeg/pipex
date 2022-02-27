/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:21:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/13 12:23:57 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

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

int	not_found(char *read_string, char *lim)
{
	if (ft_strncmp(read_string, lim, ft_strlen(lim)) == 0)
	{
		if (read_string[ft_strlen(lim)] == '\n'
			&& read_string[ft_strlen(lim) + 1] == '\0')
			return (1);
	}
	return (0);
}
