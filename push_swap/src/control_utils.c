/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:00:28 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:11:40 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_traverse_stack(t_stack *stack)
{
	t_node	*current;

	current = NULL;
	current = stack->top;
	while (current != NULL)
	{
		ft_printf(":%d ", current->value);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_print_value(t_node *node, char *text)
{
	if (node != NULL)
		ft_printf(text, node->value);
	else
		ft_printf("Node is empty!\n");
}

void	ft_print_position(t_node *node, char *text)
{
	if (node != NULL)
		ft_printf(text, node->position);
	else
		ft_printf("Node is empty!\n");
}
