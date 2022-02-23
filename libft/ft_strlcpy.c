/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:27:05 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 12:34:28 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_of_src;

	size_of_src = 0;
	while (src[size_of_src] != '\0')
		size_of_src++;
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}	
	return (size_of_src);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char src1[10] = "Bonjour";
	char dst1[10];
	char src2[10] = "Bonjour";	
	char dst2[10];

	printf("%zu\n", strlcpy(dst1, src1, 4));
	printf("%zu\n", ft_strlcpy(dst2, src2, 4));
	printf("%s\n", dst1);
	printf("%s\n", dst2);
}*/
