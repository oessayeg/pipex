/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:09:26 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 15:00:37 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*fill_my_string(char *filled_string)
{
	char	*string_to_fill;
	int		m;

	m = 0;
	string_to_fill = (char *)malloc(ft_strlen(filled_string) + 1);
	if (!string_to_fill)
		return (NULL);
	while (filled_string[m] != '\0')
	{
		string_to_fill[m] = filled_string[m];
		m++;
	}
	string_to_fill[m] = '\0';
	return (string_to_fill);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*little_s;
	char	*sub_string;
	size_t	compteur;
	size_t	letter_count;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	letter_count = 0;
	compteur = 0;
	little_s = (char *)malloc(ft_strlen(s) + 1);
	if (!little_s)
		return (NULL);
	while (s[start] != '\0' && letter_count != len)
	{
		little_s[compteur] = s[start];
		letter_count++;
		start++;
		compteur++;
	}
	little_s[compteur] = '\0';
	sub_string = fill_my_string(little_s);
	free(little_s);
	return (sub_string);
}

/*
#include <stdio.h>
int main(void)
{
	char *word = "bonjour mon ami";
	printf("%s\n", ft_substr(word, 2, 7));
	return(0);
}*/
