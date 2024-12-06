/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:10:08 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/04 14:36:00 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_op(t_stack *stack)
{
	t_node	*second;
	t_node	*third;

	second = NULL;
	third = NULL;
	second = stack->top->next;
	if (second->next != NULL)
	{
		third = second->next;
		third->prev = stack->top;
		stack->top->next = third;
	}
	stack->top->prev = second;
	second->prev = NULL;
	if (stack->size == 2)
	{
		stack->top->next = NULL;
		stack->bottom = stack->top;
	}
	second->next = stack->top;
	stack->top = second;
}

void	ft_swap_stack(t_stack *stack)
{
	if (stack->size > 1)
	{
		ft_swap_op(stack);
	}
}

void	ft_sa(t_stack *sa)
{
	ft_swap_stack(sa);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *sb)
{
	ft_swap_stack(sb);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack *sa, t_stack *sb)
{
	ft_swap_stack(sa);
	ft_swap_stack(sb);
	ft_putstr_fd("ss\n", 1);
}
