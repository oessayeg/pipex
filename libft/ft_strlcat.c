/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:48:00 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 19:47:47 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	compteur1;
	size_t	compteur2;
	size_t	len_of_dst;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	len_of_dst = ft_strlen(dst);
	compteur1 = len_of_dst;
	compteur2 = 0;
	if (dstsize <= compteur1)
		return (ft_strlen(src) + dstsize);
	while (src[compteur2] != '\0' && compteur2 < (dstsize - len_of_dst - 1))
	{
		dst[compteur1] = src[compteur2];
		compteur1++;
		compteur2++;
	}
	dst[compteur1] = '\0';
	return (len_of_dst + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char mot1[20] = "bonjour ";
	char mot2[10] = "mon ami.";
	char mot3[20] = "bonjour ";
	char mot4[10] = "mon ami.";
	printf("%lu, ", strlcat(mot1, mot2, 18));
	printf("%s", mot1);
	printf("%lu, ", ft_strlcat(mot3, mot4, 18));
	printf("%s", mot1);
}*/
