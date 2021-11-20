/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:08:12 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/22 00:50:33 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	need_reverse_rotate(t_data *data)
{
	int		max;

	if (data->stack_b)
		max = get_max(data->stack_b);
	while (*(int *)ft_lstlast(data->stack_a)->content != data->current_sorted)
	{
		if (data->stack_b && *(int *)data->stack_b->content != max)
			reverse_rotate(data, 'r');
		else
			reverse_rotate(data, 'a');
	}
}

void	move_to_b_limit_part(t_data *data, int limit)
{
	while (*(int *)data->stack_a->content <= limit \
		&& *(int *)data->stack_a->content != data->nums_sorted[0])
	{
		if (is_next_sorted(data, *(int *)data->stack_a->content))
		{
			data->current_sorted = *(int *)data->stack_a->content;
			data->count_sorted++;
			rotate(data, 'a');
		}
		else
			push(data, 'b');
	}
	if (data->stack_b && is_next_sorted(data, get_min(data->stack_b)))
		move_to_a(data);
}

void	move_to_b_limit(t_data *data, int limit)
{
	int		mid;

	mid = get_mid(data, data->stack_a, \
		get_size_limit(data, data->stack_a, limit));
	while (*(int *)data->stack_a->content <= limit \
		&& *(int *)data->stack_a->content != data->nums_sorted[0])
	{
		if (*(int *)data->stack_a->content < mid)
			push(data, 'b');
		else
			rotate(data, 'a');
	}
	need_reverse_rotate(data);
	if (data->stack_b && is_next_sorted(data, get_min(data->stack_b)))
		move_to_a(data);
}

void	move_to_b(t_data *data)
{
	int		size;
	int		mid;

	size = data->size_a;
	mid = get_mid(data, data->stack_a, size);
	while (size--)
	{
		if (*(int *)data->stack_a->content < mid)
			push(data, 'b');
		else
			rotate(data, 'a');
	}
	move_to_a(data);
}
