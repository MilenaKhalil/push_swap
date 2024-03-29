/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:54:19 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/18 16:20:00 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include "push_swap_bonus.h"

void	swap(t_list **stack, char *str);
void	swaps(t_list **stack_a, t_list **stack_b, char *com, char *str);
void	push(t_list **stack_a, t_list **stack_b, char *com, char *str);
void	rotate(t_list **stack, int rev, char *str);
void	rotations(t_list **stack_a, t_list **stack_b, char *com, char *str);
void	bad_exit(t_list **a);
void	good_exit(t_list **a);
void	inter_command(t_list **a, t_list **b, char *com, char *str);
void	check_dup(t_list **stack_a);
void	insert_el(t_list **a, t_list **b, int pos_a, int pos_b);
void	stack_rot(t_list **stack, int pos, char *com, char *rev);
void	free_mem(char **t, int i);

int		get_elem(t_list *stack, int pos);
int		get_pos(t_list *stack, int elem);
int		maximum(int a, int b);
int		itoa(t_list **a, char *str);
int		find_place(t_list *iter, int elem, int min, int max);
int		find_best(t_list *a, t_list *b, int min, int max);

char	**clean_input(char **argv);

#endif
