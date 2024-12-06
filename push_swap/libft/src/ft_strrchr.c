/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:51:42 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 12:25:57 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str_end;

	str_end = (char *)s + ft_strlen(s);
	while (str_end > s && *str_end != (char)c)
		str_end--;
	if (*str_end == (char)c)
		return (str_end);
	return (NULL);
}
