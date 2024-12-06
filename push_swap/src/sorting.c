/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:22:01 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:12:17 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	if (ft_get_highest_val(stack) == stack->bottom)
		ft_sa(stack);
	else if (ft_get_highest_val(stack) == stack->top)
	{
		ft_ra(stack);
		if (!ft_asc_sort_stack(stack))
			ft_sa(stack);
	}
	else
	{
		ft_rra(stack);
		if (!ft_asc_sort_stack(stack))
			ft_sa(stack);
	}
}

int32_t	ft_sort_to_three(t_stack *stack)
{
	if (stack->size == 1)
		return (1);
	else if (stack->size == 2 && !ft_asc_sort_stack(stack))
	{
		ft_ra(stack);
		return (1);
	}
	else if (stack->size == 3 && !ft_asc_sort_stack(stack))
	{
		ft_sort_three(stack);
		return (1);
	}
	else
		return (0);
}
