/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:07:12 by terden            #+#    #+#             */
/*   Updated: 2024/11/05 11:02:08 by terden           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, long nb, int len)
{
	int	i;

	i = len - 1;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		leng;
	char	*str;
	long	nb;

	nb = n;
	leng = num_len(n);
	str = (char *)malloc(sizeof(char) * (leng + 1));
	if (!str)
		return (NULL);
	str[leng] = '\0';
	if (nb == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		fill_str(str + 1, nb, leng - 1);
	}
	else
		fill_str(str, nb, leng);
	return (str);
}
