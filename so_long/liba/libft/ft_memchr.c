/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:31:28 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:38:54 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*sor;
	unsigned char	ch;

	sor = (unsigned char *)s;
	ch = (unsigned char)c;
	while (len--)
	{
		if (*sor == ch)
			return (sor);
		sor++;
	}
	return (0);
}
