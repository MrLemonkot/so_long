/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:53:59 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:42:49 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*nbm;
	size_t	vse;

	vse = size * number;
	nbm = (void *)malloc(vse);
	if (nbm == NULL)
		return (0);
	ft_bzero(nbm, vse);
	return (nbm);
}
