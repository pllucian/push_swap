/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:12:35 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/22 00:45:51 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	need_rotate_a(t_data *data)
{
	while (is_next_sorted(data, *(int *)data->stack_a->content))
	{
		data->current_sorted = *(int *)data->stack_a->content;
		data->count_sorted++;
		rotate(data, 'a');
	}
}

void	need_rotate_b(t_data *data)
{
	int		size;
	int		max_order;

	size = data->size_b;
	max_order = get_order(data->stack_b, get_max(data->stack_b));
	if (max_order <= size / 2 + size % 2)
		rotate(data, 'b');
	else
		reverse_rotate(data, 'b');
}

void	move_to_a_bottom(t_data *data)
{
	data->current_sorted = *(int *)data->stack_b->content;
	data->count_sorted++;
	push(data, 'a');
	rotate(data, 'a');
}

void	move_to_a_part(t_data *data)
{
	if (*(int *)data->stack_b->content == get_max(data->stack_b))
		push(data, 'a');
	else if (is_next_sorted(data, *(int *)data->stack_b->content))
		move_to_a_bottom(data);
	else
		need_rotate_b(data);
}

void	move_to_a(t_data *data)
{
	int		size;
	int		mid;
	int		max;

	size = data->size_b;
	mid = get_mid(data, data->stack_b, size);
	max = get_max(data->stack_b);
	while (size--)
	{
		if (data->size_b <= 12)
			move_to_a_part(data);
		else if (is_next_sorted(data, *(int *)data->stack_b->content))
			move_to_a_bottom(data);
		else if (*(int *)data->stack_b->content >= mid)
			push(data, 'a');
		else
			rotate(data, 'b');
	}
	need_rotate_a(data);
	if (data->stack_b)
		move_to_a(data);
	if (get_size_limit(data, data->stack_a, max) >= 24)
		move_to_b_limit(data, max);
	move_to_b_limit_part(data, max);
}
