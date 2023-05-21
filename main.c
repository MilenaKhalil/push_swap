/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/03 21:27:11 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

t_list	*get_input(int argc, char **argv)
{
	t_list	*a;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;

	a = get_input(argc, argv);
	return (0);
}