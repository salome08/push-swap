/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shazan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:03:56 by shazan            #+#    #+#             */
/*   Updated: 2015/03/24 14:17:14 by shazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# define KRED "\x1B[31m"
# define RESET "\033[0m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"

typedef struct			s_list
{
	int					data;
	struct s_list		*next;
	struct s_list		*previous;
}						t_list;

typedef struct			s_all
{
	char				*av1;
	int					k;
}						t_all;

void					call_pushswap(t_list *first, t_list *first2, \
		t_all *all, char **av);
void					ft_putstr(char *c);
void					test_int(char **arg);
void					test_int2(char **arg, int i, int j);
void					test_int3(char **arg, int i, int j);
int						test_doublon(char **arg);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_itoa(int n);
size_t					ft_nbrlen(int n);
void					ft_display_list(t_list *first);
t_list					*go_previous(t_list *first);
int						is_order(t_list *first);
int						ft_strlen(char *str);
int						ft_atoi(const char *str, t_all *all);
int						ft_isspace(int c);
int						ft_isdigit(int c, t_all *all);
t_list					*ft_create_elem(int data);
void					ft_add_elem(t_list *first, t_list *add);
void					swap_a(t_list *first, t_all *all);
void					rotate_a(t_list *first, t_all *all);
void					push_b(t_list **first, t_list **first2, t_all *all);
void					push_a(t_list **first, t_list **first2, t_all *all);
t_list					*reverse_rotate_a(t_list *first, t_all *all);
int						find_smallest(int a, t_list *first);
int						find_pos_smallest(t_list *first);
void					push_swap(t_list **first, t_list **first2, t_all *all);
int						push_swap2(t_list **first, t_list **first2, t_all *all);
int						size_list(t_list *first);

#endif
