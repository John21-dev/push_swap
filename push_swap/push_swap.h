/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:50:19 by jmacera-          #+#    #+#             */
/*   Updated: 2024/03/04 11:27:03 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_node
{
	int				value;
	int				position;
	int				r_distance;
	int				rr_distance;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}		t_stack;

void	ft_sa(t_stack *sa);
void	ft_sb(t_stack *sb);
void	ft_ss(t_stack *sa, t_stack *sb);
void	ft_pa(t_stack *from_sb, t_stack *to_sb);
void	ft_pb(t_stack *from_sb, t_stack *to_sb);
void	ft_ra(t_stack *sa);
void	ft_rb(t_stack *sb);
void	ft_rr(t_stack *sa, t_stack *sb);
void	ft_rotate(t_stack *stack);
void	ft_rra(t_stack *sa);
void	ft_rrb(t_stack *sb);
void	ft_rrr(t_stack *sa, t_stack *sb);
void	ft_rev_rot(t_stack *stack);
void	ft_delete_nodes(t_stack *stack);
void	ft_start_stack(t_stack *stack);
void	ft_traverse_stack(t_stack *stack);
void	ft_print_value(t_node *node, char *text);
void	ft_push(t_stack *stack, int val);
void	ft_pop(t_stack *stack);
void	ft_delete_array(char **array);
void	ft_ra_push(t_stack *sa);
void	ft_sort_three(t_stack *stack);
void	ft_turk_sort(t_stack *sa, t_stack *sb);
void	ft_index_stack(t_stack *stack);
void	ft_calc_distance(t_stack *stack);
void	ft_find_closest_smaller_number_in_b(t_stack *sa, t_stack *sb);
void	ft_reverse_to_top(t_stack *stack, t_node *node, char *str);
void	ft_rotate_to_top(t_stack *stack, t_node *node, char *str);
void	ft_mov_nod_top_a(t_stack *sa, t_stack *sb, t_node *selected_node);
void	ft_find_closest_bigger_number_in_a(t_stack *sb, t_stack *sa);
void	ft_move_nodes_a_to_b(t_stack *sa, t_stack *sb);
void	ft_move_nodes_b_to_a(t_stack *sb, t_stack *sa);
void	ft_mov_nod_top_b(t_stack *sa, t_stack *sb, t_node *selected_node);
void	ft_move_ops_end(t_node *node_a, t_node *node_b,
			t_stack *sa, t_stack *sb);
void	ft_move_ops_middle(t_node *node_a, t_node *node_b,
			t_stack *sa, t_stack *sb);

t_node	*ft_get_highest_val(t_stack *stack);
t_node	*ft_get_smallest_val(t_stack *stack);
t_node	*ft_select_nodes_to_push(t_stack *stack);

long	verify(const char *string);

bool	ft_is_int32(char *arg);
bool	ft_valid_num(char *str);
bool	ft_have_duplicates(t_stack *stack);
bool	ft_arg_valid_num(char **args);
bool	ft_asc_sort_stack(t_stack *stack);

int32_t	ft_convert_input_str(char *argv[], t_stack *stack);
int32_t	ft_convert_args(int argc, char **argv, t_stack *stack);
int32_t	ft_sort_to_three(t_stack *stack);
int32_t	ft_nodes_cost(t_node *node);

int		ft_load_input(int argc, char *argv[], t_stack *stack);

#endif
