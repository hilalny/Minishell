/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayaman <ayaman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:34:31 by ayaman            #+#    #+#             */
/*   Updated: 2023/05/10 23:48:16 by ayaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

char	*ft_itoa(int number)
{
	char	*ptr;
	int		len;
	int		temp_number;

	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (number == 0)
		return (ft_strdup("0"));
	temp_number = number;
	len = get_numbercount(temp_number);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (number < 0)
	{
		ptr[0] = '-';
		number *= -1;
	}
	ptr[len--] = 0;
	while (number)
	{
		ptr[len--] = '0' + (number % 10);
		number /= 10;
	}
	return (ptr);
}

/*
	bir sayinin kac basamakli oldugunu anlamamizi saglar.
*/
int	get_numbercount(int number)
{
	int	len;

	len = 0;
	if (number < 0)
	{
		len++;
	}
	while (number)
	{
		len++;
		number /= 10;
	}
	return (len);
}
