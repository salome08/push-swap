/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:48:16 by shazan            #+#    #+#             */
/*   Updated: 2015/03/24 14:08:29 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_a(t_list *first, t_all *all)
{
	int tmp;

	tmp = first->next->data;
	first->next->data = first->data;
	first->data = tmp;
	if (all->k > 0)
		write(1, " ", 1);
	ft_putstr(KRED);
	write(1, "sa", 3);
	ft_putstr(RESET);
	(all->k)++;
}

void		rotate_a(t_list *first, t_all *all)
{
	int tmp;

	tmp = first->data;
	while (first->next)
	{
		first->data = first->next->data;
		first = first->next;
	}
	first->data = tmp;
	if (all->k > 0)
		write(1, " ", 1);
	ft_putstr(GREEN);
	write(1, "ra", 3);
	ft_putstr(RESET);
	(all->k)++;
}

t_list		*reverse_rotate_a(t_list *first, t_all *all)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = first;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next->next = first;
	tmp->next = NULL;
	tmp2->previous = NULL;
	first->previous = tmp2;
	if (all->k > 0)
		write(1, " ", 1);
	ft_putstr(YELLOW);
	write(1, "rra", 4);
	ft_putstr(RESET);
	(all->k)++;
	return (tmp2);
}

void		push_b(t_list **first, t_list **first2, t_all *all)
{
	t_list *tmp;

	tmp = *first;
	*first = (*first)->next;
	tmp->next = *first2;
	*first2 = tmp;
	(*first)->previous = NULL;
	if (all->k > 0)
		write(1, " ", 1);
	ft_putstr(BLUE);
	write(1, "pb", 3);
	ft_putstr(RESET);
	(all->k)++;
}

void		push_a(t_list **first, t_list **first2, t_all *all)
{
	t_list *tmp;

	tmp = *first2;
	*first2 = (*first2)->next;
	tmp->next = *first;
	*first = tmp;
	if (all->k > 0)
		write(1, " ", 1);
	ft_putstr(MAGENTA);
	write(1, "pa", 3);
	ft_putstr(RESET);
	(all->k)++;
}
