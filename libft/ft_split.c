/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:40:30 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 19:57:32 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*static int	count_words(char const *st, char deli)
{
	int	count;
	int	compteur;

	if (!st)
		return (0);
	compteur = 0;
	count = 0;
	while (st[compteur] != '\0')
	{
		if (compteur == 0 && st[compteur] != deli)
			count++;
		else if (st[compteur] != deli && st[compteur - 1] == deli)
			count++;
		compteur++;
	}
	return (count);
}

static int	*len_of_words(char const *my_string, char dtr)
{
	int	n;
	int	*array_of_sizes;
	int	index;

	index = 0;
	n = 0;
	array_of_sizes = ft_calloc(count_words(my_string, dtr), sizeof(int));
	if (!array_of_sizes)
		return (0);
	while (my_string[n] == dtr)
		n++;
	while (my_string[n] != '\0')
	{
		if (my_string[n] != dtr)
			array_of_sizes[index]++;
		else if (my_string[n] == dtr && my_string[n + 1] != dtr)
		{
			array_of_sizes[index]++;
			index++;
		}
		n++;
	}
	array_of_sizes[index]++;
	return (array_of_sizes);
}

static char	**copy_strings(char **re_string, char const *strii, char dm, int n)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	while (strii[n] != '\0')
	{
		if (strii[n] != dm)
		{
			re_string[i1][i2] = strii[n];
			i2++;
		}
		else if ((strii[n] == dm && strii[n + 1] != dm)
			|| strii[n + 1] == '\0')
		{
			re_string[i1][i2] = '\0';
			i2 = 0;
			i1++;
		}
		n++;
	}
	return (re_string);
}

static int	give_index(char const *sttt, char ddd)
{
	int	lo;

	lo = 0;
	while (sttt[lo] == ddd && sttt[lo] != '\0')
		lo++;
	return (lo);
}

char	**ft_split(char const *s, char d)
{
	char	**return_string;
	int		*sizes_in_arr;
	int		com;
	int		m;

	if (!s)
		return (NULL);
	m = 0;
	com = 0;
	sizes_in_arr = len_of_words(s, d);
	return_string = (char **)malloc(sizeof(char *) * (count_words(s, d) + 1));
	if (!(return_string))
		return (NULL);
	while (com < count_words(s, d))
	{
		return_string[com] = (char *)malloc(sizeof(char) * sizes_in_arr[com]);
		if (!return_string[com])
			return (NULL);
		com++;
	}
	return_string[com] = NULL;
	m = give_index(s, d);
	return_string = copy_strings(return_string, s, d, m);
	free(sizes_in_arr);
	return (return_string);
}*/

#include <stdlib.h>

static int		unleah(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int		count_w(const char *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == charset || str[i + 1] == '\0') == 1
				&& (str[i] == charset || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void		write_word(char *dest, const char *from, char charset)
{
	int	i;

	i = 0;
	while ((from[i] == charset || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int		write_split(char **split, const char *str, char charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == charset || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == charset || str[i + j] == '\0') == 0)
				j++;
			if ((split[word] = (char*)malloc(sizeof(char) * (j + 1))) == NULL)
				return (unleah(split, word - 1));
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char			**ft_split(const char *str, char c)
{
	char	**res;
	int		n_word;

	n_word = count_w(str, c);
	if ((res = (char**)malloc(sizeof(char*) * (n_word + 1))) == NULL)
		return (NULL);
	res[n_word] = 0;
	if (write_split(res, str, c) == -1)
		return (NULL);
	return (res);
}

