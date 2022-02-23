/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:59:00 by oessayeg          #+#    #+#             */
/*   Updated: 2022/02/07 11:27:05 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*pointer;
	unsigned char	*j;
	size_t			compteur;

	compteur = 0;
	pointer = malloc(size * count);
	if (!pointer)
		return (NULL);
	j = (unsigned char *)pointer;
	while (compteur < size * count)
	{
		*j = 0;
		compteur++;
		j++;
	}
	return (pointer);
}
/*#include <stdio.h>
int main(void)
{
	int *tab;
}*/
