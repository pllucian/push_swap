/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:47:06 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/21 01:53:03 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_part(t_data *data, int c)
{
	t_list	*tmp;
	int		size;

	if ((c == 'b' || c == 'r') && data->stack_b && data->stack_b->next)
	{
		size = ft_lstsize(data->stack_b);
		tmp = ft_lstlast(data->stack_b);
		ft_lstadd_front(&data->stack_b, tmp);
		tmp = data->stack_b;
		while (--size)
			tmp = tmp->next;
		tmp->next = NULL;
		if (c == 'b')
			ft_putendl_fd("rrb", 1);
	}
	if (c == 'r' && data->stack_a && data->stack_a->next \
		&& data->stack_b && data->stack_b->next)
		ft_putendl_fd("rrr", 1);
}

void	reverse_rotate(t_data *data, int c)
{
	t_list	*tmp;
	int		size;

	if ((c == 'a' || c == 'r') && data->stack_a && data->stack_a->next)
	{
		size = ft_lstsize(data->stack_a);
		tmp = ft_lstlast(data->stack_a);
		ft_lstadd_front(&data->stack_a, tmp);
		tmp = data->stack_a;
		while (--size)
			tmp = tmp->next;
		tmp->next = NULL;
		if (c == 'a')
			ft_putendl_fd("rra", 1);
	}
	reverse_rotate_part(data, c);
}

void	rotate(t_data *data, int c)
{
	t_list	*tmp;

	if ((c == 'a' || c == 'r') && data->stack_a && data->stack_a->next)
	{
		tmp = data->stack_a;
		data->stack_a = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(&data->stack_a, tmp);
		if (c == 'a')
			ft_putendl_fd("ra", 1);
	}
	if ((c == 'b' || c == 'r') && data->stack_b && data->stack_b->next)
	{
		tmp = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(&data->stack_b, tmp);
		if (c == 'b')
			ft_putendl_fd("rb", 1);
	}
	if (c == 'r' && data->stack_a && data->stack_a->next \
		&& data->stack_b && data->stack_b->next)
		ft_putendl_fd("rr", 1);
}

void	push(t_data *data, int c)
{
	t_list	*tmp;

	if ((c == 'a' && !data->stack_b) || (c == 'b' && !data->stack_a))
		return ;
	if (c == 'a')
	{
		tmp = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(&data->stack_a, tmp);
		data->size_a++;
		data->size_b--;
		ft_putendl_fd("pa", 1);
	}
	else if (c == 'b')
	{
		tmp = data->stack_a;
		data->stack_a = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(&data->stack_b, tmp);
		data->size_b++;
		data->size_a--;
		ft_putendl_fd("pb", 1);
	}
}

void	swap(t_data *data, int c)
{
	t_list	*tmp;

	if ((c == 'a' || c == 's') && data->stack_a && data->stack_a->next)
	{
		tmp = data->stack_a;
		data->stack_a = tmp->next;
		tmp->next = data->stack_a->next;
		data->stack_a->next = tmp;
		if (c == 'a')
			ft_putendl_fd("sa", 1);
	}
	if ((c == 'b' || c == 's') && data->stack_b && data->stack_b->next)
	{
		tmp = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = data->stack_b->next;
		data->stack_b->next = tmp;
		if (c == 'b')
			ft_putendl_fd("sb", 1);
	}
	if (c == 's' && data->stack_a && data->stack_a->next \
		&& data->stack_b && data->stack_b->next)
		ft_putendl_fd("ss", 1);
}
