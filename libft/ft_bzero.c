/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:13:08 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 12:11:15 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*x;
	size_t			compteur;

	x = (unsigned char *)s;
	compteur = 0;
	while (compteur < n)
	{
		*x = 0;
		compteur++;
		x++;
	}
}
/*
#include <stdio.h>
#include <strings.h>
int main(void)
{
	int c;
	c = 0;
	int tab[8] = {9, 2, 3, 32, 1, 32, 1, 1};
	ft_bzero(tab, sizeof(int) * 8);
	while (c < 8)
	{
		printf("%d, ", tab[c]);
		c++;
	}
}*/
