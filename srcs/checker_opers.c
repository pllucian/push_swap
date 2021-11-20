/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:56:51 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 23:57:19 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	}
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
	}
	if ((c == 'b' || c == 'r') && data->stack_b && data->stack_b->next)
	{
		tmp = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(&data->stack_b, tmp);
	}
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
	}
	else if (c == 'b')
	{
		tmp = data->stack_a;
		data->stack_a = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(&data->stack_b, tmp);
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
	}
	if ((c == 'b' || c == 's') && data->stack_b && data->stack_b->next)
	{
		tmp = data->stack_b;
		data->stack_b = tmp->next;
		tmp->next = data->stack_b->next;
		data->stack_b->next = tmp;
	}
}
