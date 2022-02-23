/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:17:58 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 13:03:09 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*n;

	n = (char *)s;
	i = 0;
	while (n[i] != '\0')
	{
		if (n[i] == (char)c)
			return (&n[i]);
		i++;
	}
	if (n[i] == (char)c)
		return (&n[i]);
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{

	printf("%s\n", ft_strchr("bonjour", 'x'));
	printf("%s\n", strchr("bonjour", 'x'));
	printf("%s\n", ft_strchr("bonjour", '\0'));
	printf("%s\n", strchr("bonjour", '\0'));
	printf("%s\n", ft_strchr("bonjour", 'j'));
	printf("%s\n", strchr("bonjour", 'j'));
}*/
