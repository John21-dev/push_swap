/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:21:14 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:12:34 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_index_stack(t_stack *stack)
{
	int32_t	index;
	t_node	*current;

	index = 1;
	current = stack->top;
	while (current != NULL)
	{
		current->position = index;
		current = current->next;
		index++;
	}
}

void	ft_calc_distance(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		current->r_distance = current->position - 1;
		current->rr_distance = (stack->size - current->position) + 1;
		current = current->next;
	}
}

t_node	*ft_select_nodes_to_push(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	t_node	*cheapest;

	current = stack->top;
	cheapest = current;
	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		if (ft_nodes_cost(cheapest) > ft_nodes_cost(next))
			cheapest = next;
		current = current->next;
	}
	return (cheapest);
}

void	ft_rotate_to_top(t_stack *stack, t_node *node, char *str)
{
	while (stack->top != node)
	{
		ft_rotate(stack);
		ft_putstr_fd(str, 1);
	}
}

void	ft_reverse_to_top(t_stack *stack, t_node *node, char *str)
{
	while (stack->top != node)
	{
		ft_rev_rot(stack);
		ft_putstr_fd(str, 1);
	}
}
