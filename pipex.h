/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:36:06 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/09 18:47:55 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"
# include <fcntl.h>

char	*find_path(char **env);
char	*give_me_command(char *command, int option);
char	*path_please(char **paths, char *command_w_slash);
void	free_everything(char **to_free1, char *to_free2, char *to_free3);
void	arg_check(int args);
void	error_message(char *string);
void	child_process1(char **argv, char **env, int *fd);
void	child_process2(char **argv, char **env, int *fd);
void	exec(char **env, char *command);
void	free_all(char **to_free);
int		no_command(char *string);
int		check_file(char *file);
int		command_check(char *command, char **env);
int		check_path(char *command);
int		len_to_space(char *str);
#endif
