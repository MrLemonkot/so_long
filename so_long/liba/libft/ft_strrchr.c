/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:09:02 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:40:49 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	len;

	len = ft_strlen(str);
	if ((char)ch == '\0')
		return (&((char *)str)[len]);
	while (len >= 0)
	{
		if (str[len] == (char)ch)
			return (&((char *)str)[len]);
		len--;
	}
	return (0);
}
