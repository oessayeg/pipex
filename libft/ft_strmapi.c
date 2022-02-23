/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:44:58 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 15:10:12 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	compteur;
	char			*new_string;

	if (s == NULL || f == NULL)
		return (NULL);
	compteur = 0;
	new_string = (char *)malloc(ft_strlen(s) + 1);
	if (new_string == NULL)
		return (NULL);
	while (s[compteur] != '\0')
	{
		new_string[compteur] = f(compteur, s[compteur]);
		compteur++;
	}
	new_string[compteur] = '\0';
	return (new_string);
}
