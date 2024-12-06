/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:24:23 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 12:25:20 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	int		n;
	char	*cpy;

	cpy = (char *)malloc(sizeof(*src) * ft_strlen(src) + 1);
	if (cpy == NULL)
		return (NULL);
	n = 0;
	while (src[n] != '\0')
	{
		cpy[n] = src[n];
		n++;
	}
	cpy[n] = '\0';
	return (cpy);
}
