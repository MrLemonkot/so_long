/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:02:26 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:44:35 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *finder, size_t len)
{
	size_t	i;
	size_t	i2;

	if (*finder == 0)
		return ((char *)str);
	i = 0;
	i2 = 0;
	while (str[i] && i < len)
	{
		if (str[i] == finder[0])
		{
			while (finder[i2] && str[i + i2] == finder[i2] && i + i2 < len)
			{
				if (finder[i2 + 1] == '\0')
					return ((char *)&str[i]);
				i2++;
			}
		}
		i++;
	}
	return (0);
}
