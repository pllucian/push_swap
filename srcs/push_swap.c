/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:19:11 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/21 01:55:38 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free(t_data *data, int rtn)
{
	if (data)
	{
		if (data->stack_b)
			ft_lstclear(&data->stack_b, NULL);
		if (data->stack_a)
			ft_lstclear(&data->stack_a, NULL);
		if (data->nums_sorted)
			free(data->nums_sorted);
		if (data->nums)
			free(data->nums);
		free(data);
	}
	if (rtn)
		ft_putendl_fd("Error", 2);
	exit(rtn);
}

int	init_data(t_data *data, char **args)
{
	int		i;
	int		j;

	data->size_a = ft_arraylen((void **)args);
	data->nums = (int *)ft_calloc(data->size_a, sizeof(int));
	data->nums_sorted = (int *)ft_calloc(data->size_a, sizeof(int));
	if (!data->nums || !data->nums_sorted)
		return (EXIT_FAILURE);
	i = -1;
	while (args[++i])
	{
		if (!ft_strisint(args[i]))
			return (EXIT_FAILURE);
		data->nums[i] = ft_atoi(args[i]);
		data->nums_sorted[i] = data->nums[i];
		ft_lstadd_back(&data->stack_a, ft_lstnew(&data->nums[i]));
		j = -1;
		while (++j < i)
		{
			if (data->nums[i] == data->nums[j])
				return (EXIT_FAILURE);
		}
	}
	quik_sort_array(data->nums_sorted, 0, data->size_a - 1);
	return (EXIT_SUCCESS);
}

int	parse_args(t_data *data, char **args)
{
	if (init_data(data, args))
	{
		ft_freearray((void **)args);
		return (EXIT_FAILURE);
	}
	ft_freearray((void **)args);
	return (EXIT_SUCCESS);
}

int	parse_argv(t_data *data, char **argv)
{
	char	**args;
	char	*argvs;
	char	*tmp;

	argvs = NULL;
	while (*(++argv))
	{
		if (!ft_strncmp(*argv, "", 1))
		{
			free(argvs);
			return (EXIT_FAILURE);
		}
		tmp = argvs;
		argvs = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = argvs;
		argvs = ft_strjoin(tmp, *argv);
		free(tmp);
	}
	args = ft_split(argvs, ' ');
	free(argvs);
	if (parse_args(data, args))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		exit_free(data, EXIT_FAILURE);
	if (parse_argv(data, argv))
		exit_free(data, EXIT_FAILURE);
	if (!is_sorted_list(data->stack_a))
		sort_data(data);
	exit_free(data, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
