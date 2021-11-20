/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:02:23 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/21 01:49:21 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_limit(t_data *data, t_list *stack, int limit)
{
	int		i;

	if (!stack)
		return (0);
	i = 0;
	while (*(int *)stack->content <= limit \
		&& *(int *)stack->content != data->nums_sorted[0])
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	get_order(t_list *stack, int value)
{
	int		order;

	if (!stack)
		return (0);
	order = 1;
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (order);
		stack = stack->next;
		order++;
	}
	return (order);
}

int	get_max(t_list *stack)
{
	int		max;

	max = *(int *)stack->content;
	while (stack->next)
	{
		if (*(int *)stack->next->content > max)
			max = *(int *)stack->next->content;
		stack = stack->next;
	}
	return (max);
}

int	get_min(t_list *stack)
{
	int		min;

	min = *(int *)stack->content;
	while (stack->next)
	{
		if (*(int *)stack->next->content < min)
			min = *(int *)stack->next->content;
		stack = stack->next;
	}
	return (min);
}

int	get_mid(t_data *data, t_list *stack, int size)
{
	int		*tmp;
	int		mid;
	int		i;

	tmp = (int *)ft_calloc(size, sizeof(int));
	if (!tmp)
		exit_free(data, EXIT_FAILURE);
	i = -1;
	while (++i < size && stack)
	{
		tmp[i] = *(int *)stack->content;
		stack = stack->next;
	}
	quik_sort_array(tmp, 0, size - 1);
	mid = tmp[size / 2];
	free(tmp);
	return (mid);
}
