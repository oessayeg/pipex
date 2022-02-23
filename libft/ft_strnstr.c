/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:42:37 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 14:41:20 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		compteur1;
	size_t		compteur2;
	size_t		compteur3;
	const char	*pt;

	compteur1 = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[compteur1] != '\0' && compteur1 < len)
	{
		compteur3 = compteur1;
		compteur2 = 0;
		if (needle[compteur2] == haystack[compteur1])
			pt = &haystack[compteur1];
		while (needle[compteur2] == haystack[compteur3] && compteur3 < len)
		{
			compteur3++;
			compteur2++;
			if (needle[compteur2] == '\0')
				return ((char *)pt);
		}
		compteur1++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%s\n", ft_strnstr("boo njour", "o", 3));
	printf("%s\n", strnstr("boo njour", "o", 3));
}*/
