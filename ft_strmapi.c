/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:16:20 by terden            #+#    #+#             */
/*   Updated: 2024/10/27 14:24:42 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	len = (unsigned int)ft_strlen(s);
	str = (char *)malloc(sizeof(char) * ((int)len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[(int)i]);
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}
