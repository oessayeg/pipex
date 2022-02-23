/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:14:24 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 14:36:33 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	int arr1[10] = {1, 2, 0, 4, 5};
	int arr2[10] = {1, 2, 4, 4, 5};
	char *word1 = "bonjour";
	char *word2 = "bonjour";
	printf("%d\n", memcmp(word1, word2, 6));
	printf("%d\n", ft_memcmp(word1, word2, 6));
	printf("%d\n", ft_memcmp(arr1, arr2, 16));
}*/
