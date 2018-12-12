/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:11:47 by shazan            #+#    #+#             */
/*   Updated: 2015/03/23 18:40:59 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			test_doublon(char **arg)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (arg[i])
	{
		while (arg[j])
		{
			if (ft_strcmp(arg[i], arg[j]))
				j++;
			else
			{
				write(1, "Error\n", 6);
				exit (0);
			}
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void		test_int(char **arg)
{
	int				i;
	int				j;

	i = 1;
	j = 1;
	while (arg[i])
	{
		if (arg[i][0] == '-')
			test_int2(arg, i, j);
		else
			test_int3(arg, i, j);
		i++;
	}
}

void		test_int2(char **arg, int i, int j)
{
	static char		neg[] = "-2147483648";

	if (ft_strlen(arg[i]) == 11)
	{
		while (arg[i][j] != '\0' && arg[i][j] >= neg[j])
		{
			if (arg[i][j] > neg[j])
			{
				write(1, "Error\n", 6);
				exit(-1);
			}
			j++;
		}
	}
	else if (ft_strlen(arg[i]) > 11)
	{
		write(1, "Error\n", 7);
		exit(-1);
	}
}

void		test_int3(char **arg, int i, int j)
{
	static char		pos[] = "2147483647";

	if (ft_strlen(arg[i]) == 10)
	{
		if (arg[i][0] < pos[0])
			return ;
		while (arg[i][j] != '\0' && arg[i][j] >= pos[j])
		{
			if (arg[i][j] > pos[j])
			{
				write(1, "Error\n", 6);
				exit(-1);
			}
			j++;
		}
	}
	else if (ft_strlen(arg[i]) > 10)
	{
		write(1, "Error\n", 7);
		exit(-1);
	}
}
