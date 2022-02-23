/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:09:09 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/08 12:14:51 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*substring;
	int		mem_size;
	int		compteur;

	compteur = 0;
	if (!s1 || !s2)
		return (NULL);
	mem_size = ft_strlen(s1) + ft_strlen(s2);
	substring = (char *)malloc(sizeof(char) * mem_size + 1);
	if (!substring)
		return (NULL);
	while (*s1 != '\0')
	{
		substring[compteur] = *s1;
		compteur++;
		s1++;
	}
	while (*s2 != '\0')
	{
		substring[compteur] = *s2;
		compteur++;
		s2++;
	}
	substring[compteur] = '\0';
	return (substring);
}
/*
#include <stdio.h>
int main(void)
{
	char word1[15] = "hello, my";
	char word2[15] = "name is jkl";
	printf("%s", ft_strjoin(word1, word2));
}*/
