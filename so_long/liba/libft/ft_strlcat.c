/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:57 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:39:57 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	i2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	i = 0;
	i2 = 0;
	if (size <= len1)
		return (size + len2);
	while (dst[i2])
		i2++;
	while ((i < size - len1 - 1 && src[i]))
	{
		dst[i2] = src[i];
		i++;
		i2++;
	}
	dst[i2] = '\0';
	return (len1 + len2);
}
