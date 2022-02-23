/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:18:38 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 13:05:09 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		compteur;
	char	*n;

	compteur = 0;
	n = (char *)s;
	while (n[compteur] != '\0')
		compteur++;
	while (compteur >= 0)
	{
		if (n[compteur] == (char)c)
			return (&n[compteur]);
		compteur--;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	const char *mot = "bjonjour";
	printf("%s\n", ft_strrchr(mot, '\0'));
	printf("%s\n", strrchr(mot, '\0'));
	printf("%s\n", ft_strrchr(mot, 'o'));
	printf("%s\n", strrchr(mot, 'o'));
}*/
