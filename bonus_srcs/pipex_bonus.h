/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:47:25 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/10 16:49:49 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>

int		check_ph(char *command);
int		no_command(char *string);
int		not_found(char *read_string, char *lim);
int		check_here_doc(char *string);
int		command_check(char *command, char **env);
int		len_to_space(char *str);
int		check_path(char *command);
void	exec_multiple_pipes(char **argv, int argc, char **env);
void	free_all(char **to_free);
void	free_everything(char **to_free1, char *to_free2, char *to_free3);
void	error_message(char *string);
void	exec_here_doc(char **argv, char **env);
void	here_doc_child1(char **argv, char **env, int *fd, int *h_fd);
void	here_doc_child2(char **argv, char **env, int *fd);
void	exec(char **env, char *command);
void	arg_check(int args);
void	first_child(char **argv, char **env);
void	middle_child(char **argv, char **env, int i);
void	final_child(char **argv, char **env, int argc);
char	*read_from_input(char *limiter);
char	*join_free(char *s1, char *s2);
char	*give_me_command(char *command, int option);
char	*path_please(char **paths, char *commmand_w_slash);
char	*find_path(char **env);
#endif
