/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:35:34 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 15:47:29 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	compteur;

	compteur = 0;
	if (!s)
		return ;
	while (s[compteur] != '\0')
	{
		write(fd, &s[compteur], 1);
		compteur++;
	}
}
