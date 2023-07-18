/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/18 18:19:33 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(char **t, int i)
{
	while (i >= 0)
	{
		free(t[i]);
		i--;
	}
	free(t);
}

void	bad_exit(t_list **a)
{
	if (a)
		ft_lstclear(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	good_exit(t_list **a)
{
	if (a)
		ft_lstclear(a);
	exit(0);
}
