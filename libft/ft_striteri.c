/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:33:52 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 15:10:45 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	compteur;

	compteur = 0;
	if (!s || !f)
		return ;
	while (s[compteur] != '\0')
	{
		(*f)(compteur, &s[compteur]);
		compteur++;
	}
}
