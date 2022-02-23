/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:37:30 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/13 12:28:16 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	arg_check(argc);
	if (check_here_doc(argv[1]) == 1 && argc == 6)
		exec_here_doc(argv, env);
	else
		exec_multiple_pipes(argv, argc, env);
}

int	check_here_doc(char *string)
{
	if (ft_strncmp(string, "here_doc", 8) == 0 && string[8] == '\0')
		return (1);
	return (0);
}

void	error_message(char *string)
{
	perror(string);
	exit(errno);
}

char	*read_from_input(char *limiter)
{
	char	*string;
	char	*ret_string;

	ret_string = NULL;
	write(1, "> ", 2);
	string = get_next_line(0);
	while (string != NULL && not_found(string, limiter) == 0)
	{
		ret_string = join_free(ret_string, string);
		write(1, "> ", 2);
		string = get_next_line(0);
	}
	if (string)
		free(string);
	return (ret_string);
}

char	*join_free(char *s1, char *s2)
{
	char	*tmp1;
	char	*tmp2;

	if (s1 == NULL)
	{
		s1 = ft_strdup(s2);
		free(s2);
		return (s1);
	}
	tmp1 = s1;
	tmp2 = s2;
	s1 = ft_strjoin(s1, s2);
	free(tmp1);
	free(tmp2);
	return (s1);
}
