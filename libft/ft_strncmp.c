/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:14:10 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 13:04:47 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while ((s1[c] != '\0' || s2[c] != '\0') && c < n)
	{
		if (s1[c] != s2[c])
			return (((unsigned char)s1[c] - (unsigned char)s2[c]));
		c++;
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%d\n", ft_strncmp("boxjour", "bonjour", 4));
	printf("%d\n", strncmp("boxjour", "bonjour", 4));
}*/
