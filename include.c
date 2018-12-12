/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:00:34 by shazan            #+#    #+#             */
/*   Updated: 2015/03/24 14:01:35 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_atoi(const char *str, t_all *all)
{
	int		nbr;
	int		i;
	int		neg;

	nbr = 0;
	i = 0;
	neg = 0;
	if (str == NULL)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	neg = i - 1;
	if (!(ft_isdigit(str[i], all)))
		return (0);
	while (str[i] && ft_isdigit(str[i], all))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (str[neg] == '-')
		nbr = -nbr;
	return (nbr);
}

int			ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int			ft_isdigit(int c, t_all *all)
{
	if (ft_strcmp(all->av1, "-n") == 0)
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	else
	{
		write (1, "Error\n", 6);
		exit (-1);
	}
	return (0);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned char		c1;
	unsigned char		c2;

	c1 = (unsigned char)*s1++;
	c2 = (unsigned char)*s2++;
	if (c1 == '\0')
		return (c1 - c2);
	while (c1 == c2)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0')
			return (c1 - c2);
	}
	return (c1 - c2);
}

int			is_order(t_list *first)
{
	t_list *tmp;

	tmp = first;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
