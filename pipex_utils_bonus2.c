/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:11:25 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/13 12:24:05 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

char	*find_path(char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i][0] != 'P' || env[i][1] != 'A' || env[i][2] != 'T'
	|| env[i][3] != 'H')
		i++;
	while (env[i][j] != '/')
		j++;
	return (&env[i][j]);
}

char	*give_me_command(char *command, int option)
{
	char	*comm_slash;
	int		i;
	int		j;

	i = 0;
	while (command[i] == ' ')
		i++;
	if (command[i] == '\0')
		return (NULL);
	comm_slash = malloc(sizeof(char) * (len_to_space(&command[i]) + 2));
	if (comm_slash == NULL)
		return (NULL);
	comm_slash[0] = '/';
	if (option == 1)
		j = 1;
	else if (option == 0)
		j = 0;
	while (command[i] != '\0' && command[i] != ' ')
	{
		comm_slash[j] = command[i];
		i++;
		j++;
	}
	comm_slash[j] = '\0';
	return (comm_slash);
}

char	*path_please(char **paths, char *command_w_slash)
{
	char	*ret_string;
	int		i;

	if (command_w_slash == NULL)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		ret_string = ft_strjoin(paths[i], command_w_slash);
		if (access(ret_string, X_OK) == 0)
			return (ret_string);
		free(ret_string);
		i++;
	}
	return (NULL);
}

int	no_command(char *string)
{
	int	i;

	i = 0;
	while (string[i] == ' ')
		i++;
	if (string[i] == '\0')
		return (0);
	return (1);
}

void	arg_check(int args)
{
	if (args < 5)
	{
		ft_putstr_fd("Bad arguments\n", 2);
		ft_putstr_fd("--> ./pipex <infile> 'cmd1' 'cmd2' ..", 2);
		ft_putstr_fd(" 'cmdn' <outfile>\n", 2);
		ft_putstr_fd("--> ./pipex here_doc 'limiter' 'cmd1'", 2);
		ft_putstr_fd(" 'cmd2' <outfile>\n", 2);
		exit(errno);
	}
}
