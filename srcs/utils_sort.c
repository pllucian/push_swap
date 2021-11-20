/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:02:15 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/19 16:42:51 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quik_sort_array(int *array, int first, int last)
{
	int		tmp;
	int		left;
	int		right;
	int		pivot;

	if (first >= last)
		return ;
	left = first;
	right = last;
	pivot = array[(first + last) / 2];
	while (left < right)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] > pivot)
			right--;
		if (left <= right)
		{
			tmp = array[left];
			array[left++] = array[right];
			array[right--] = tmp;
		}
	}
	quik_sort_array(array, first, right);
	quik_sort_array(array, left, last);
}

int	is_next_sorted(t_data *data, int value)
{
	int		i;

	i = -1;
	while (++i < data->size_a && data->count_sorted)
	{
		if (data->nums_sorted[i] == data->current_sorted)
			return (value == data->nums_sorted[i + 1]);
	}
	return (value == data->nums_sorted[i]);
}

int	is_sorted_list(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}
