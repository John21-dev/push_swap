/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:24:07 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 12:25:01 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putnbr_fd (-21, fd);
			ft_putnbr_fd (47483648, fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb >= 0 && nb < 10)
	{
		nb = nb + '0';
		ft_putchar_fd(nb, fd);
	}
	else
	{
		ft_putnbr_fd (nb / 10, fd);
		nb = nb % 10 + '0';
		ft_putchar_fd(nb, fd);
	}
}
