/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:44:13 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 13:26:57 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;

	string = (unsigned char *)s;
	while (n > 0)
	{
		if (*string == (unsigned char)c)
			return (string);
		string++;
		n--;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char word[20] = "bonjour";
	printf("%s\n", ft_memchr(word, 'o', 5));
	printf("%s\n", memchr(word, 'o', 5));
}*/
