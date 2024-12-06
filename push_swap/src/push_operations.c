/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:38:44 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:12:00 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_nod_normal(t_stack *src_stack, t_stack *dst_stack)
{
	t_node	*src_temp;
	t_node	*dst_temp;

	src_temp = NULL;
	dst_temp = NULL;
	if (src_stack->size > 1)
	{
		src_temp = src_stack->top->next;
		src_temp->prev = NULL;
	}
	else
		src_stack->bottom = NULL;
	if (dst_stack->size > 0)
	{
		dst_temp = dst_stack->top;
		dst_temp->prev = src_stack->top;
	}
	else
		dst_stack->bottom = src_stack->top;
	dst_stack->top = src_stack->top;
	dst_stack->top->next = dst_temp;
	dst_stack->top->prev = NULL;
	dst_stack->size++;
	src_stack->top = src_temp;
	src_stack->size--;
}

void	ft_pop_push(t_stack *src_stack, t_stack *dst_stack)
{
	if (src_stack->size != 0)
	{
		ft_nod_normal(src_stack, dst_stack);
	}
	return ;
}

void	ft_pb(t_stack *from_sa, t_stack *to_sb)
{
	ft_pop_push(from_sa, to_sb);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_stack *from_sb, t_stack *to_sa)
{
	ft_pop_push(from_sb, to_sa);
	ft_putstr_fd("pa\n", 1);
}
