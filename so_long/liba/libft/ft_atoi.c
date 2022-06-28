/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:23:45 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:42:32 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			znak;
	long int	number;
	long int	oldnum;

	i = 0;
	number = 0;
	znak = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') \
	|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		znak = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str [i] <= '9')
	{
		oldnum = number;
		number *= 10;
		number += ((int)str[i] - '0');
		i++;
		if ((oldnum < 0 && number > 0) || (oldnum > 0 && number < 0))
			return ((znak == 1) * -1);
	}
	return (number * znak);
}
