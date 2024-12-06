/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:36 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:12:13 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_asc_sort_stack(t_stack *stack)
{
	t_node		*node;
	t_node		*next_node;
	int32_t		value;

	node = stack->top;
	while (node != NULL && node->next != NULL)
	{
		value = node->value;
		next_node = node->next;
		if (value > next_node->value)
			return (0);
		node = next_node;
	}
	return (1);
}
