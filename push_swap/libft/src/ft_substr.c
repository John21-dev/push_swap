/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:24:54 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:15:55 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_start_is_bigger(char *ptr)
{
	ptr = malloc(1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	*ptr = '\0';
	return (ptr);
}

char	*ft_start_is_smaller(char *ptr, unsigned int start,
				size_t str_size, char const *s)
{
	int		i;
	char	*start_ptr;

	i = 0;
	ptr = malloc(((str_size - start) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	start_ptr = ptr;
	i = str_size - start;
	s += start;
	while (i-- > 0)
		*ptr++ = *s++;
	*ptr = '\0';
	return (start_ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*start_ptr;
	size_t	s_len;
	size_t	str_size;

	ptr = NULL;
	s_len = len;
	str_size = ft_strlen(s);
	if (start > str_size)
		return (ft_start_is_bigger(ptr));
	if (start <= str_size && s_len >= str_size)
		return (ft_start_is_smaller(ptr, start, str_size, s));
	ptr = malloc((len + 1) * sizeof(char));
	start_ptr = ptr;
	if (ptr == NULL)
		return (NULL);
	s += (start);
	while (len-- > 0)
		*ptr++ = *s++;
	*ptr = '\0';
	return (start_ptr);
}
