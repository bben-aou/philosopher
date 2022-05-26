/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virsnp00x <virsnp00x@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:16:33 by virsnp00x         #+#    #+#             */
/*   Updated: 2022/05/26 15:16:37 by virsnp00x        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philosophers.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			r = (r * 10) + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (r * s);
}