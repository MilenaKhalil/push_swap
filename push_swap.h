
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:54:19 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/23 18:15:30 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_garb
{
    char    *prog_name;
	t_list	*stack_a;
    t_list  *stack_b;
    t_list  *a;
    t_list  *b;
}	t_garb;

typedef struct s_com
{
	struct s_com	*next;
    char            *command;
}	t_com;

void    swap(t_list **stack, char *str);
void    swaps(t_list **stack_a, t_list **stack_b, char *com, char *str);
void    push(t_list **stack_a, t_list **stack_b, char *com, char *str);
void    rotate(t_list **stack, int rev, char *str);
void    rotations(t_list **stack_a, t_list **stack_b, char *com, char *str);
void	bad_exit(t_list **a);
void	good_exit(t_list **a);
void    sort_stack(t_list **stack_a, t_list **stack_b);
void    inter_command(t_list **a, t_list **b, char *com, char *str);
void	print_stack(t_list *ab);                                              // I will have to remove it

#endif
