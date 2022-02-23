/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:03:18 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 15:03:09 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_beggining(char const *strg, char const *sett, int index)
{
	int	compteur1;

	compteur1 = 0;
	while (sett[compteur1] != '\0')
	{
		if (sett[compteur1] == strg[index])
			return (1);
		compteur1++;
	}
	if (strg[index] == '\0')
		return (2);
	return (0);
}

static int	is_last(char const *strgg, char const *settt, int index)
{
	int	compteur2;

	compteur2 = 0;
	while (settt[compteur2] != '\0')
	{
		if (strgg[index] == settt[compteur2])
			return (1);
		compteur2++;
	}
	return (0);
}

static char	*give_me_string(char const *f_str, char *ret_stri, int ii1, int ii2)
{
	int	c;

	c = 0;
	while (ii1 <= ii2)
	{
		ret_stri[c] = f_str[ii1];
		ii1++;
		c++;
	}
	ret_stri[c] = '\0';
	return (ret_stri);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i1;
	int		i2;
	char	*return_string;

	if (!s1 || !set)
		return (NULL);
	i1 = 0;
	i2 = ft_strlen(s1) - 1;
	while (is_beggining(s1, set, i1) == 1)
		i1++;
	if (is_beggining(s1, set, i1) == 2)
		return (ft_strdup(""));
	while (is_last(s1, set, i2) == 1)
		i2--;
	return_string = (char *)malloc(sizeof(char) * (i2 - i1) + 2);
	if (!return_string)
		return (NULL);
	return_string = give_me_string(s1, return_string, i1, i2);
	return (return_string);
}

/*
#include <stdio.h>
int main(void)
{
	int c;
	
	c = 0;

	printf("%s", ft_strtrim("        ", " "));
}*/
