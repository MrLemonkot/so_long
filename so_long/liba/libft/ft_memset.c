/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:17:05 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:39:14 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*src;
	unsigned char	ch;

	src = (unsigned char *)dest;
	ch = (unsigned char)c;
	while (len--)
	{
		*src++ = ch;
	}
	return (dest);
}
