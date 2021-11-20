/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:16:14 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/22 00:40:16 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

typedef struct s_data
{
	int		size_a;
	int		size_b;
	int		*nums;
	int		*nums_sorted;
	int		count_sorted;
	int		current_sorted;
	t_list	*stack_a;
	t_list	*stack_b;
}		t_data;

void	ft_freearray(void **array);
size_t	ft_arraylen(void **array);
int		ft_strisdigit(char *str);
int		ft_strisint(char *str);

int		get_size_limit(t_data *data, t_list *stack, int limit);
int		get_order(t_list *stack, int value);
int		get_max(t_list *stack);
int		get_min(t_list *stack);
int		get_mid(t_data *data, t_list *stack, int size);

void	quik_sort_array(int *array, int first, int last);
int		is_next_sorted(t_data *data, int value);
int		is_sorted_list(t_list *stack);

void	reverse_rotate_part(t_data *data, int c);
void	reverse_rotate(t_data *data, int c);
void	rotate(t_data *data, int c);
void	push(t_data *data, int c);
void	swap(t_data *data, int c);

void	need_reverse_rotate(t_data *data);
void	move_to_b_limit_part(t_data *data, int limit);
void	move_to_b_limit(t_data *data, int limit);
void	move_to_b(t_data *data);

void	need_rotate_a(t_data *data);
void	need_rotate_b(t_data *data);
void	move_to_a_bottom(t_data *data);
void	move_to_a_part(t_data *data);
void	move_to_a(t_data *data);

void	advanced_sort(t_data *data);
void	simple_sort(t_data *data);
void	sort_data(t_data *data);

void	exit_free(t_data *data, int rtn);
int		init_data(t_data *data, char **args);
int		parse_args(t_data *data, char **args);
int		parse_argv(t_data *data, char **argv);

#endif
