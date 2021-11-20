/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:35:36 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/21 01:56:55 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	launch_opers(t_data *data, char *line)
{
	if (!ft_strncmp(line, "s", 1))
		swap(data, line[1]);
	else if (!ft_strncmp(line, "p", 1))
		push(data, line[1]);
	else if (!ft_strncmp(line, "rr", 2))
		reverse_rotate(data, line[2]);
	else
		rotate(data, line[1]);
}

int	check_opers(char *line)
{
	if (!ft_strncmp(line, "sa", 3) || !ft_strncmp(line, "sb", 3) \
		|| !ft_strncmp(line, "ss", 3) || !ft_strncmp(line, "pa", 3) \
		|| !ft_strncmp(line, "pb", 3) || !ft_strncmp(line, "ra", 3) \
		|| !ft_strncmp(line, "rb", 3) || !ft_strncmp(line, "rr", 3) \
		|| !ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrb", 4) \
		|| !ft_strncmp(line, "rrr", 4))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	parse_opers(t_data *data)
{
	char	*line;
	int		i;

	while (true)
	{
		i = get_next_line(0, &line);
		if (!i && ft_strncmp(line, "", 1))
		{
			free(line);
			return (EXIT_FAILURE);
		}
		else if (!i)
			break ;
		else if (check_opers(line))
		{
			free(line);
			return (EXIT_FAILURE);
		}
		launch_opers(data, line);
		free(line);
	}
	free(line);
	return (EXIT_SUCCESS);
}
