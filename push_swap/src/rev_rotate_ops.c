/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:49:40 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:12:05 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rev_normal(t_stack *stack)
{
	t_node	*temp_bottom_prev;

	temp_bottom_prev = stack->bottom->prev;
	stack->top->prev = stack->bottom;
	temp_bottom_prev->next = NULL;
	stack->bottom->next = stack->top;
	stack-> bottom->prev = NULL;
	stack->top = stack->bottom;
	stack->bottom = temp_bottom_prev;
}

void	ft_rev_rot(t_stack *stack)
{
	if (stack->size > 1)
	{
		ft_rev_normal(stack);
	}
}

void	ft_rra(t_stack *sa)
{
	ft_rev_rot(sa);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack *sb)
{
	ft_rev_rot(sb);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *sa, t_stack *sb)
{
	ft_rev_rot(sa);
	ft_rev_rot(sb);
	ft_putstr_fd("rrr\n", 1);
}
