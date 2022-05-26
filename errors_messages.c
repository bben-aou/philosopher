/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:11:07 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/05/26 14:00:38 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_display_msg(char *str)
{
    int i;
    char *ptr;

    i = 0;
    ptr = str;
    while (*ptr++)
        i++;
    write(2, str, i);
    exit (1);
}

void    ft_errors_msg(int i)
{
    if (i == 1)
        ft_display_msg("⛔ ERROR : invalid arguments\n");        
    if (i == 2)
        ft_display_msg("⛔ ERROR : invalid number of philosophers\n");
    if (i == 3)
        ft_display_msg("⛔ ERROR : invalid time of sleeping \n");
    if (i == 4)
        ft_display_msg("⛔ ERROR : invalid time of eating  \n");
    if (i == 5)
        ft_display_msg("⛔ ERROR : invalid time of dying  \n");
    if (i == 6)
        ft_display_msg("⛔ ERROR : invalid number_of_times_each_philosopher_must_eat  \n");
    if (i == 7)
        ft_display_msg("⛔ ERROR : allocation failed \n");
    if (i == 8)
        ft_display_msg("⛔ ERROR : simulation failed ! (check data init) \n");
}