/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:30:56 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/09 16:50:21 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int x, int y)
{
	int	i;
	int	res;

	if (!y)
		return (1);
	i = y;
	res = x;
	while (--i > 0)
	{
		res *= x;
	}
	return (res);
}

void	strres(char (*str)[], int lenght)
{
	int	i;

	i = 0;
	while (i < lenght)
		(*str)[i++] = '\0';
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
