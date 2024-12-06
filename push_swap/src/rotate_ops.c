/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:11:35 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/11 12:00:22 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_normal(t_stack *stack)
{
	t_node	*temp_top_next;

	temp_top_next = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->next = NULL;
	stack->top->prev = stack->bottom;
	stack->bottom = stack->top;
	temp_top_next->prev = NULL;
	stack->top = temp_top_next;
}

void	ft_rotate(t_stack *stack)
{
	if (stack->size > 1)
	{
		ft_normal(stack);
	}
}

void	ft_ra(t_stack *sa)
{
	ft_rotate(sa);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack *sb)
{
	ft_rotate(sb);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rr(t_stack *sa, t_stack *sb)
{
	ft_rotate(sa);
	ft_rotate(sb);
	ft_putstr_fd("rr\n", 1);
}
