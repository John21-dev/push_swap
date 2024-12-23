/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:29:22 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:12:21 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack *stack, int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = val;
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top != NULL)
		stack->top->prev = node;
	if (stack->top == NULL)
		stack->bottom = node;
	stack->top = node;
	stack->size++;
}

void	ft_pop(t_stack *stack)
{
	t_node	*temp;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		temp->next->prev = NULL;
		stack->size--;
		free(temp);
	}
	else if (stack->top != NULL)
	{
		temp = stack->top;
		stack->top = NULL;
		stack->size--;
		free(temp);
	}
}

void	ft_ra_push(t_stack *sa)
{
	ft_rotate(sa);
}

t_node	*ft_get_highest_val(t_stack *stack)
{
	t_node	*top;
	t_node	*highest_value;

	top = stack->top;
	highest_value = top;
	while (top != NULL)
	{
		if (top->value > highest_value->value)
			highest_value = top;
		top = top->next;
	}
	return (highest_value);
}

t_node	*ft_get_smallest_val(t_stack *stack)
{
	t_node	*top;
	t_node	*smallest_value;

	top = stack->top;
	smallest_value = top;
	while (top != NULL)
	{
		if (top->value < smallest_value->value)
			smallest_value = top;
		top = top->next;
	}
	return (smallest_value);
}
