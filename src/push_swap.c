/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:56:54 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/02 02:45:58 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char **push_swap (int ac, char **args)
{
    int i;
    char *str;
    char **av;

    i = 1;
    str = NULL;
    av = NULL;
    while (i < ac)
    {
        str = ft_strjoin(str, " ");
        str = ft_strjoin(str, args[i]);
        i++;
    }
    av = ft_split(str, ' ');
    free(str);
    if(!is_all_digits(av) || !exist_duplicates(av))
    {
        ft_putstr_fd("Error\n", 2);
        free_vector(av);
        exit(-1);
    }
    return av;
}

int main (int ac, char **args)
{
    char **av;
    stack *stack_a;
    stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2 || !args[0])
        return (-1);
    av = push_swap(ac, args);
    init_stack(&stack_a, av);
    free_vector(av);
    if(is_sorted(stack_a))
        return (0); 
    sort_stack(&stack_a, &stack_b);
    free_stack (stack_a);
    return (0);
}
