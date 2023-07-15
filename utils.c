/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/06 19:13:53 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bad_exit(t_list **a)
{
	ft_lstclear(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	good_exit(t_list **a)
{
	ft_lstclear(a);
	exit(0);
}

void	print_stack(t_list *ab)                      // надо будет потом удалить эту штуку!!! 
{
	int	i;

	i = 0;
	while (ab)
	{
		printf("el[%d] = %d ", i, ab->content);
		ab = ab->next;
		i++;
	}
	printf("\n");
}

void    inter_command(t_list **a, t_list **b, char *com, char *str)
{
    if (com[0] == 's')
        swaps(a, b, com, str);
    else if (com[0] == 'p')
        push(a, b, com, str);
    else
        rotations(a, b, com, str);
}
