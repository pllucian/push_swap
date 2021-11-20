/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:37:11 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/21 01:41:58 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <stdbool.h>

typedef struct s_data
{
	int		*nums;
	t_list	*stack_a;
	t_list	*stack_b;
}		t_data;

void	ft_freearray(void **array);
size_t	ft_arraylen(void **array);
int		ft_strisdigit(char *str);
int		ft_strisint(char *str);

void	reverse_rotate_part(t_data *data, int c);
void	reverse_rotate(t_data *data, int c);
void	rotate(t_data *data, int c);
void	push(t_data *data, int c);
void	swap(t_data *data, int c);

int		is_sorted_list(t_list *stack);
void	launch_opers(t_data *data, char *line);
int		check_opers(char *line);
int		parse_opers(t_data *data);

void	exit_free(t_data *data, int rtn);
int		init_data(t_data *data, char **args);
int		parse_args(t_data *data, char **args);
int		parse_argv(t_data *data, char **argv);

#endif
