/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:54:19 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/18 16:20:41 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include "push_swap.h"

void	swap(t_list **stack, char *str);
void	swaps(t_list **stack_a, t_list **stack_b, char *com, char *str);
void	push(t_list **stack_a, t_list **stack_b, char *com, char *str);
void	rotate(t_list **stack, int rev, char *str);
void	rotations(t_list **stack_a, t_list **stack_b, char *com, char *str);
void	bad_exit(t_list **a);
void	good_exit(t_list **a);
void	inter_command(t_list **a, t_list **b, char *com, char *str);
void	check_dup(t_list **stack_a);

int		itoa(t_list **a, char *str);

#endif
