/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:36:13 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/11 11:51:05 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int c)
{
	unsigned char	digit;

	if (c == EOF)
		return (0);
	if (c < 256)
	{
		digit = (unsigned char) c;
		if (digit >= '0' && digit <= '9' )
			return (1);
	}
	return (0);
}
