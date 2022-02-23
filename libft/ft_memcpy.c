/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:20:16 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 12:24:27 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst1;
	const unsigned char	*src1;
	size_t				i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (const unsigned char *)src;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char mot1[10] = "bonjour";
	char dest1[10] = "hello";
	char mot2[10] = "bonjour";
	char dest2[10] = "hello";
	printf("%s\n", ft_memcpy(dest1, mot1, 2));
	printf("%s\n", memcpy(dest2, mot2, 2));

	int arr1[10] = {0, 0, 0, 1, 2, 3};
	int arr2[10] = {0, 0, 0, 1, 2, 3};
	ft_memcpy(arr1, (arr1  + 3), sizeof(int) * 3);
	int i = 0;
	while (i < 6)
	{
		printf("%d\n", arr1[i]);
		i++;
	}
	return (0);
}*/
