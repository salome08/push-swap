/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 13:10:01 by shazan            #+#    #+#             */
/*   Updated: 2015/03/23 18:41:49 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_smallest(int a, t_list *first)
{
	int		test;
	t_list	*tmp;

	tmp = first;
	test = first->data;
	while (tmp)
	{
		if (a == 1)
		{
			if (tmp->data < test)
				test = tmp->data;
			tmp = tmp->next;
		}
		else if (a == 2)
		{
			if (tmp->data > test)
				test = tmp->data;
			tmp = tmp->next;
		}
	}
	return (test);
}

int			find_pos_smallest(t_list *first)
{
	t_list	*tmp;
	int		test;
	int		i;

	i = 1;
	tmp = first;
	test = find_smallest(1, first);
	while (tmp->data != test)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void		push_swap(t_list **first, t_list **first2, t_all *all)
{
	int		a;
	t_list	*tmp;

	(void)first2;
	tmp = *first;
	a = find_pos_smallest(*first);
	if (tmp->data > tmp->next->data)
	{
		swap_a(*first, all);
		return ;
	}
	if (a == size_list(*first))
	{
		*first = reverse_rotate_a(*first, all);
		return ;
	}
	if (push_swap2(first, first2, all) == 2)
		return ;
	if (a == 1)
		push_b(first, first2, all);
	else
		*first = reverse_rotate_a(*first, all);
}

int			push_swap2(t_list **first, t_list **first2, t_all *all)
{
	t_list *tmp;

	tmp = *first;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	if (tmp->previous->data > tmp->data && \
			tmp->previous->data == find_smallest(2, *first))
	{
		if (size_list(*first) < 5)
			push_b(first, first2, all);
		else
		{
			*first = reverse_rotate_a(*first, all);
			*first = reverse_rotate_a(*first, all);
			swap_a(*first, all);
			rotate_a(*first, all);
			rotate_a(*first, all);
		}
		return (2);
	}
	return (0);
}

int			size_list(t_list *first)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = first;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
