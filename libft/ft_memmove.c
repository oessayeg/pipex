/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:17:34 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 12:31:15 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (src < dst)
	{
		while (len--)
			dst2[len] = src2[len];
	}
	else if (src > dst)
	{
		while (len > 0)
		{
			*dst2 = *src2;
			dst2++;
			src2++;
			len--;
		}
	}
	return (dst);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char word1[10] = "bonjour";
	char word2[10] = "jour";
	char word3[10] = "bonjour";
	char word4[10] = "jour";
	printf("%s\n", memmove(word1, word2, 2));
	printf("%s\n", word1);
	printf("%s\n", ft_memmove(word3, word4, 2));
	printf("%s\n", word3);
}*/
