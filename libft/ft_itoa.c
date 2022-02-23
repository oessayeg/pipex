/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:51:51 by oessayeg          #+#    #+#             */
/*   Updated: 2021/11/18 15:09:04 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	alloc_size(int num)
{
	int	return_value;

	return_value = 1;
	while (num > 9 || num < -9)
	{
		num /= 10;
		return_value++;
	}
	return (return_value);
}

static char	*first_step(int numb, char *str1)
{
	int	compteur;

	compteur = 0;
	while (numb > 9 || numb < -9)
	{
		if (numb > 0)
			str1[compteur] = (numb % 10) + '0';
		else
			str1[compteur] = -1 * (numb % 10) + '0';
		numb /= 10;
		compteur++;
	}
	if (numb >= 0)
		str1[compteur] = (numb % 10) + '0';
	else
	{
		str1[compteur] = -1 * (numb % 10) + '0';
		compteur++;
		str1[compteur] = '-';
	}
	compteur++;
	str1[compteur] = '\0';
	return (str1);
}

static char	*rev_my_string(char *stg_rev, char *good_stg)
{
	int	l;
	int	h;

	h = 0;
	l = 0;
	l = ft_strlen(stg_rev);
	l--;
	while (l >= 0)
	{
		good_stg[h] = stg_rev[l];
		h++;
		l--;
	}
	good_stg[h] = '\0';
	return (good_stg);
}

char	*ft_itoa(int n)
{
	char	*reverse_string;
	char	*good_string;

	if (n < 0)
	{
		reverse_string = (char *)malloc(sizeof(char) * alloc_size(n) + 2);
		good_string = (char *)malloc(sizeof(char) * alloc_size(n) + 2);
	}
	else
	{
		reverse_string = (char *)malloc(sizeof(char) * alloc_size(n) + 1);
		good_string = (char *)malloc(sizeof(char) * alloc_size(n) + 1);
	}
	if (!reverse_string || !good_string)
		return (NULL);
	reverse_string = first_step(n, reverse_string);
	good_string = rev_my_string(reverse_string, good_string);
	free(reverse_string);
	return (good_string);
}
/*#include <stdio.h>
int main(void)
{
	printf("%s'\n", ft_itoa(-1));
	printf("%s'\n", ft_itoa(-10));
	printf("%s'\n", ft_itoa(-100));
	printf("%s'\n", ft_itoa(-2147483648));
	printf("%s'\n", ft_itoa(1000));
	printf("%s'\n", ft_itoa(100));
	printf("%s'\n", ft_itoa(10));
	printf("%s'\n", ft_itoa(1));
}*/
