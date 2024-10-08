/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:30:56 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/05 18:47:12 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	power(char x, char y)
{
	int		i;
	char	res;

	if (!y)
		return (1);
	i = y;
	res = x;
	while (--i)
	{
		res *= x;
	}
	return (res);
}

int	numlen(unsigned int i)
{
	int	res;

	res = 0;
	while (i)
	{
		i /= 10;
		res++;
	}
	return (res);
}
