/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:36:56 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 12:03:05 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				compteur;
	unsigned char		*x;

	compteur = 0;
	x = (unsigned char *)b;
	while (compteur < len)
	{
		*x = (unsigned char)c;
		compteur++;
		x++;
	}
	return (b);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	unsigned char s1[20] = "Bonjour.";
	unsigned char s2[20] = "Bonjour.";
	printf("%s\n", memset(s1, 91, 3));
	printf("%s\n", ft_memset(s2, 91, 3));
	
	int c;
	c = 0;
	int tab[8] = {9, 2, 3, 32, 1, 32, 1, 1};
	ft_memset(tab, 1, sizeof(int) * 8);
	while (c < 8)
	{
		printf("%d, ", tab[c]);
		c++;
	}
	return (0);
}*/
