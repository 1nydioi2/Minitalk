/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:30:38 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/03 02:14:30 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_number(char str[])
{
	while(*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoui(char s[])
{
	unsigned int	res;

	res = 0;
	while (*s)
	{
		res *= 10;
		res += (*s - '0');
		s++;
	}
	return (res);
}

void	char_to_sig(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{	
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
	}
}

void	received(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Glad you liked this one :)\n", 28);
	else if (signum == SIGUSR2)
		write(1, "Glad you liked this one too :)\n", 32);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
		return (write(1, "Wrong argument amount\n" , 23));
	if (is_number(argv[1]))
		return (write(1, "PID format not recognized\n", 27));
	str = argv[2];
	pid = ft_atoui(argv[1]);
	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	while (*str)
	{
		char_to_sig(*str, pid);
		str++;
	}
	return (0);
}
