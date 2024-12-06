/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:45:36 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:12:46 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_is_int32(char *arg)
{
	long long	num;

	num = verify(arg);
	if (num <= INT32_MAX && num >= INT32_MIN)
		return (true);
	else
		return (false);
	return (true);
}

bool	ft_valid_num(char *str)
{
	if (*str == '-')
		str++;
	while (*str != '\0')
		if (!ft_isdigit(*(str++)))
			return (false);
	return (true);
}

static int	ft_space(int c)
{
	unsigned char	l;

	l = (unsigned char) c;
	if (l == ' ' || l == '\f' || l == '\n' || l == '\r'
		|| l == '\t' || l == '\v')
		return (1);
	return (0);
}

long	verify(const char *string)
{
	int		is_negative;
	long	result;

	result = 0;
	is_negative = 0;
	while (ft_space(*string))
		string++;
	if (*string == '-')
	{
		is_negative = 1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (ft_isdigit(*string))
	{
		if (!ft_isdigit(*(string + 1)))
		{
			if (is_negative)
				return ((result += ((long) *string) - 48) * -1);
			return (result += ((long) *string) - 48);
		}
		result = (result + (((long) *string++) - 48)) * 10;
	}
	return (0);
}
