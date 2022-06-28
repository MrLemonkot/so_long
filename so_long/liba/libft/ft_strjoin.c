/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:34:10 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:44:07 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s12 = malloc(sizeof(char) * (ft_strlen((char *)s1) + \
ft_strlen((char *)s2) + 1));
	if (s12 == NULL)
		return (NULL);
	while (*s1)
	{
		s12[i++] = *s1++;
	}
	while (*s2)
	{
		s12[i++] = *s2++;
	}
	s12[i] = '\0';
	return (s12);
}
