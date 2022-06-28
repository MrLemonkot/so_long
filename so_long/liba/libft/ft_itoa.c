/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:14:05 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:43:21 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlen_ft(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*null_m(int n, char *str)
{
	if (n == 0)
		str[0] = '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		num;
	int		znak;
	char	*str;
	int		len;

	znak = 1;
	num = n;
	if (n < 0)
		znak = -1;
	len = strlen_ft(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	null_m(n, str);
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (char)((n % 10) * ((2 * (n > 0)) - 1) + '0');
		n /= 10;
	}
	len--;
	if (znak < 0)
		str[len] = '-';
	return (str);
}
