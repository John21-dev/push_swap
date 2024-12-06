/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:21:04 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/11 12:38:19 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int32_t	ft_nodes_cost(t_node *node)
{
	int32_t	node_pair_cost;

	if (node->r_distance <= node->rr_distance)
	{
		if (node->target_node->r_distance <= node->target_node->rr_distance)
			node_pair_cost = node->r_distance + node->target_node->rr_distance;
		else
			node_pair_cost = node->r_distance + node->target_node->rr_distance;
	}
	else
	{
		if (node->target_node->r_distance <= node->target_node->rr_distance)
			node_pair_cost = node->rr_distance + node->target_node->r_distance;
		else
			node_pair_cost = node->rr_distance + node->target_node->rr_distance;
	}
	return (node_pair_cost);
}

void	ft_move_ops_end(t_node *node_a, t_node *node_b,
		t_stack *sa, t_stack *sb)
{
	if (node_a->r_distance <= node_a->rr_distance)
		ft_rotate_to_top(sa, node_a, "ra\n");
	else if (node_a->r_distance > node_a->rr_distance)
		ft_reverse_to_top(sa, node_a, "rra\n");
	if (node_b->r_distance <= node_b->rr_distance)
		ft_rotate_to_top(sb, node_b, "rb\n");
	else if (node_b->r_distance > node_b->rr_distance)
		ft_reverse_to_top(sb, node_b, "rrb\n");
}

void	ft_move_ops_middle(t_node *node_a, t_node *node_b,
		t_stack *sa, t_stack *sb)
{
	if (sa->top != node_a)
		ft_reverse_to_top(sa, node_a, "rra\n");
	else if (sb->top != node_b)
		ft_reverse_to_top(sb, node_b, "rrb\n");
}

void	ft_mov_nod_top_a(t_stack *sa, t_stack *sb, t_node *selec_node)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = selec_node;
	node_b = node_a->target_node;
	if (node_a->r_distance <= node_a->rr_distance
		&& node_b->r_distance <= node_b->rr_distance)
	{
		while (sa->top != node_a && sb->top != node_b)
			ft_rr(sa, sb);
		if (sa->top != node_a)
			ft_rotate_to_top(sa, node_a, "ra\n");
		else if (sb->top != node_b)
			ft_rotate_to_top(sb, node_b, "rb\n");
	}
	else if (node_a->r_distance > node_a->rr_distance
		&& node_b->r_distance > node_b->rr_distance)
	{
		while (sa->top != node_a && sb->top != node_b)
			ft_rrr(sa, sb);
		ft_move_ops_middle(node_a, node_b, sa, sb);
	}
	else
		ft_move_ops_end(node_a, node_b, sa, sb);
}

void	ft_mov_nod_top_b(t_stack *sa, t_stack *sb, t_node *selec_node)
{
	t_node	*node_a;
	t_node	*node_b;

	node_b = selec_node;
	node_a = node_b->target_node;
	if (node_a->r_distance <= node_a->rr_distance
		&& node_b->r_distance <= node_b->rr_distance)
	{
		while (sa->top != node_a && sb->top != node_b)
			ft_rr(sa, sb);
		if (sa->top != node_a)
			ft_rotate_to_top(sa, node_a, "ra\n");
		else if (sb->top != node_b)
			ft_rotate_to_top(sb, node_b, "rb\n");
	}
	else if (node_a->r_distance > node_a->rr_distance
		&& node_b->r_distance > node_b->rr_distance)
	{
		while (sa->top != node_a && sb->top != node_b)
			ft_rrr(sa, sb);
		ft_move_ops_middle(node_a, node_b, sa, sb);
	}
	else
		ft_move_ops_end(node_a, node_b, sa, sb);
}
