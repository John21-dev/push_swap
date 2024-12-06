/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:13:12 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/11 12:58:26 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_find_closest_smaller_number_in_b(t_stack *sa, t_stack *sb)
{
	t_node	*cur_a;
	t_node	*cur_b;
	t_node	*target_node;
	long	best_match_value;

	cur_a = sa->top;
	while (cur_a != NULL)
	{
		best_match_value = LONG_MIN;
		cur_b = sb->top;
		while (cur_b != NULL)
		{
			if (cur_b->value < cur_a->value && cur_b->value > best_match_value)
			{
				best_match_value = cur_b->value;
				target_node = cur_b;
			}
			cur_b = cur_b->next;
			if (best_match_value == LONG_MIN)
				cur_a->target_node = ft_get_highest_val(sb);
			else
				cur_a->target_node = target_node;
		}
		cur_a = cur_a->next;
	}
}

void	ft_find_closest_bigger_number_in_a(t_stack *sb, t_stack *sa)
{
	t_node	*cur_a;
	t_node	*cur_b;
	t_node	*target_node;
	long	best_match_value;

	cur_b = sb->top;
	while (cur_b != NULL)
	{
		best_match_value = LONG_MAX;
		cur_a = sa->top;
		while (cur_a != NULL)
		{
			if (cur_a->value > cur_b->value && cur_a->value < best_match_value)
			{
				best_match_value = cur_a->value;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
			if (best_match_value == LONG_MAX)
				cur_b->target_node = ft_get_smallest_val(sa);
			else
				cur_b->target_node = target_node;
		}
		cur_b = cur_b->next;
	}
}

void	ft_move_nodes_a_to_b(t_stack *sa, t_stack *sb)
{
	t_node	*cheapest;

	while (sb->size < 2 && sa->size > 3)
		ft_pb(sa, sb);
	while (sa->size > 3)
	{
		ft_index_stack(sa);
		ft_index_stack(sb);
		ft_calc_distance(sa);
		ft_calc_distance(sb);
		ft_find_closest_smaller_number_in_b(sa, sb);
		cheapest = ft_select_nodes_to_push(sa);
		ft_mov_nod_top_a(sa, sb, cheapest);
		ft_pb(sa, sb);
	}
}

void	ft_move_nodes_b_to_a(t_stack *sb, t_stack *sa)
{
	t_node	*cheapest;

	while (sb->top != NULL)
	{
		ft_index_stack(sa);
		ft_index_stack(sb);
		ft_calc_distance(sa);
		ft_calc_distance(sb);
		ft_find_closest_bigger_number_in_a(sb, sa);
		cheapest = ft_select_nodes_to_push(sb);
		ft_mov_nod_top_b(sa, sb, cheapest);
		ft_pa(sb, sa);
	}
}

void	ft_turk_sort(t_stack *sa, t_stack *sb)
{
	t_node	*smallest_node;

	ft_move_nodes_a_to_b(sa, sb);
	if (!ft_asc_sort_stack(sa))
		ft_sort_three(sa);
	ft_move_nodes_b_to_a(sb, sa);
	ft_index_stack(sa);
	ft_calc_distance(sa);
	smallest_node = ft_get_smallest_val(sa);
	if (smallest_node != sa->top)
	{
		while (sa->top != smallest_node)
		{
			if (smallest_node->r_distance < smallest_node->rr_distance)
				ft_ra(sa);
			else
				ft_rra(sa);
		}
	}
}
