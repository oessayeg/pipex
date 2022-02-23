/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:20:55 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 14:58:55 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len_of_s1;
	int		compteur;
	char	*copy;

	len_of_s1 = 0;
	compteur = 0;
	while (s1[len_of_s1] != '\0')
		len_of_s1++;
	copy = (char *)malloc(sizeof(char) * len_of_s1 + 1);
	if (!copy)
		return (NULL);
	while (s1[compteur] != '\0')
	{
		copy[compteur] = s1[compteur];
		compteur++;
	}
	copy[compteur] = '\0';
	return (copy);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char mot1[10] = "Bjour";
	const char mot2[10] = "Bjour";
	printf("%s\n", ft_strdup(mot1));
	printf("%s\n", strdup(mot2));
}*/
