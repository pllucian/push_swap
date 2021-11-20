/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:07:46 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/22 00:59:48 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	advanced_sort(t_data *data)
{
	move_to_b(data);
	while (get_size_limit(data, data->stack_a, get_max(data->stack_a)) >= 24)
		move_to_b_limit(data, get_max(data->stack_a));
	move_to_b_limit_part(data, get_max(data->stack_a));
}

void	simple_sort(t_data *data)
{
	int		mid;
	int		max;

	mid = data->nums_sorted[data->size_a / 2];
	max = data->nums_sorted[data->size_a - 1];
	while (data->size_a > 3)
	{
		if (*(int *)data->stack_a->content < mid)
			push(data, 'b');
		else
			rotate(data, 'a');
	}
	if (data->size_a > 2 && *(int *)data->stack_a->content == max)
		rotate(data, 'a');
	if (data->size_a > 2 && *(int *)data->stack_a->next->content == max)
		reverse_rotate(data, 'a');
	if (*(int *)data->stack_a->content > *(int *)data->stack_a->next->content)
		swap(data, 'a');
	while (data->stack_b)
		push(data, 'a');
	if (*(int *)data->stack_a->content > *(int *)data->stack_a->next->content)
		swap(data, 'a');
}

void	sort_data(t_data *data)
{
	if (data->size_a <= 5)
		simple_sort(data);
	else
		advanced_sort(data);
}
