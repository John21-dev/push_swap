/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:33:36 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/01 16:11:52 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_delete_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->top;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
		temp = NULL;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	ft_delete_array(char **array)
{
	char	**arr;

	arr = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free(arr);
}

void	ft_start_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
