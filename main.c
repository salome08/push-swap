/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:47:35 by shazan            #+#    #+#             */
/*   Updated: 2015/03/24 14:05:14 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	int		i;
	t_list	*first;
	t_list	*elem;
	t_list	*first2;
	t_all	all;

	i = 2;
	all.k = 0;
	if (ac <= 1)
		exit (0);
	all.av1 = av[1];
	if (ft_strcmp(all.av1, "-n") == 0)
		i = 3;
	first2 = 0;
	test_int(av);
	test_doublon(av);
	first = ft_create_elem(ft_atoi(av[i - 1], &all));
	while (i < ac)
	{
		elem = ft_create_elem(ft_atoi(av[i], &all));
		ft_add_elem(first, elem);
		i++;
	}
	call_pushswap(first, first2, &all, av);
	return (0);
}

void		call_pushswap(t_list *first, t_list *first2, t_all *all, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (!(is_order(first)))
		push_swap(&first, &first2, all);
	if (first2)
	{
		j = size_list(first2);
		while (j > 0)
		{
			push_a(&first, &first2, all);
			j--;
		}
	}
	write(1, "\n", 1);
	if (ft_strcmp(av[1], "-n") == 0)
	{
		write(1, ft_itoa(all->k), ft_strlen(ft_itoa(all->k)));
		write(1, "\n", 1);
	}
}

void		ft_add_elem(t_list *first, t_list *add)
{
	t_list *tmp;

	tmp = first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
	add->previous = tmp;
}

t_list		*ft_create_elem(int data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	elem->next = NULL;
	elem->previous = NULL;
	elem->data = data;
	return (elem);
}

t_list		*go_previous(t_list *first)
{
	t_list *tmp;

	tmp = first;
	while (tmp && tmp->previous)
	{
		tmp = tmp->previous;
	}
	first = tmp;
	return (first);
}
