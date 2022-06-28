/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:05:01 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:39:40 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str && *str != (char)ch)
	{
		str++;
	}
	if (*str == (char)ch)
		return ((char *)str);
	else if ((char)ch == '\0')
		return ((char *)str);
	else
		return (0);
}
