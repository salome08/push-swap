/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:19:55 by shazan            #+#    #+#             */
/*   Updated: 2015/03/24 14:03:10 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_display_list(t_list *first)
{
	t_list *tmp;

	tmp = first;
	while (tmp)
	{
		tmp = tmp->next;
	}
}

static int	ft_abs(int n)
{
	int	ret;

	ret = (n < 0) ? -n : n;
	return (ret);
}

char		*ft_itoa(int n)
{
	char	*s;
	size_t	i;

	i = ft_nbrlen(n);
	i += (n < 0) ? 1 : 0;
	s = (char *)malloc(i + 1);
	s[i] = '\0';
	if (n < 0)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	while (i-- && n)
	{
		s[i] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (s);
}

size_t		ft_nbrlen(int n)
{
	size_t	i;

	i = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void		ft_putstr(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}
