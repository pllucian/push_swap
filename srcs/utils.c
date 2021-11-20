/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:42:54 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/22 01:32:53 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freearray(void **array)
{
	void	**tmp;

	if (!array)
		return ;
	tmp = array;
	while (*tmp)
	{
		free(*tmp);
		*tmp++ = NULL;
	}
	free(array);
}

size_t	ft_arraylen(void **array)
{
	size_t		len;

	if (!array)
		return (0);
	len = 0;
	while (*array++)
		len++;
	return (len);
}

int	ft_strisdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit((int)*str++))
			return (false);
	}
	return (true);
}

int	ft_strisint(char *str)
{
	int		sign;

	sign = 0;
	if (*str == '+')
	{
		sign = 1;
		str++;
	}
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!ft_strisdigit(str))
		return (false);
	if (sign)
		str--;
	if (sign == 0 && ft_strlen(str) >= 10 && ft_atoi(str) == -1)
		return (false);
	else if (sign == 1 && ft_strlen(str) >= 10 && ft_atoi(str) == -1)
		return (false);
	else if (sign == -1 && ft_strlen(str) >= 10 && ft_atoi(str) == 0)
		return (false);
	return (true);
}
