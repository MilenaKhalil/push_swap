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

#include "push_swap.h"

void    error_exit(char *prog_name, char *message)
{
    ft_putstr_fd(prog_name, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(message, 2);
    exit (1);
}

int	get_int(const char *str, char *prog_name)
{
	int		i;
	int		min;
	int		res;

	min = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		min = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
    if (str[i] != 0 && !(str[i] >= '0' && str[i] <= '9'))
        error_exit(prog_name, "Error: argument is not an int\n");
	return (res * min);
}

t_list	**get_input(int argc, char **argv)
{
	t_list	**a;
    t_list  *new;
	int		i;

	i = 1;
    a = 0;
	while (i < argc)
	{
		new->content = get_int(argv[i], argv[0]);       // надо будет сделать фриинг если плохие аргументы
        new->next = 0;
        if (a == 0)
            a = &new;
        else
            ft_lstadd_back(a, new);
        printf("adress = %p\n", new->next);
        printf("Next arg = %d\n", ft_lstlast(*a)->content);
        i++;
	}
    return (a);
}

void    print_list(t_list   **a)
{
    if (!a || !(*a))
        return ;
    while ((*a)->next)
    {
        printf("%d ", (*a)->content);
        *a = (*a)->next;
    }
    printf("/n");
}

int	main(int argc, char **argv)
{
	t_list	**a;

    //(void) argv;
    //(void) argc;
    if (argc == 1)
        error_exit(argv[0], "Error: not enough arguments\n");
    a = get_input(argc, argv);
    print_list(a);
    //printf("%d\n", get_int(argv[1], argv[0]));
//	a = get_input(argc, argv);
	return (0);
}
