/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:59:23 by jmacera-          #+#    #+#             */
/*   Updated: 2024/02/29 17:19:21 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	sa;
	t_stack	sb;

	ft_start_stack(&sa);
	ft_start_stack(&sb);
	if (ft_load_input(argc, argv, &sa))
		return (1);
	if (!ft_have_duplicates(&sa))
	{
		ft_putstr_fd("Error: Duplicate value.\n", 2);
		ft_delete_nodes(&sa);
		return (1);
	}
	if (ft_asc_sort_stack(&sa))
		return (ft_delete_nodes(&sa), 0);
	if (!ft_sort_to_three(&sa))
	{
		ft_turk_sort(&sa, &sb);
		ft_delete_nodes(&sa);
		return (0);
	}
	ft_delete_nodes(&sa);
	return (0);
}
