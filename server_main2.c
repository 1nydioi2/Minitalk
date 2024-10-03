/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:55 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/03 12:50:49 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	bin[9];

void	btoa(void)
{
	char	c;
	int	i;
	char	p;

	c = 0;
	i = 0;
	p = 7;
	while (bin[i] && i < 8)
	{
		if (bin[i] == '1')
			c += power(2, p);
		i++;
		p--;
	}
	write(1, &c, 1);
}

void	binres(void)
{
	int	i;

	i = 9;
	while (i--)
		bin[i] = '\0';
}

char	*ft_uitoa(unsigned int pid)
{
	int	i;
	int	len;
	int	m;
	char	*str;

	i = 0;
	m = 1;
	len = numlen(pid);
	str = malloc(sizeof(char) * (len + 1));
	while (--len)
		m *= 10;
	while (m)
	{
		str[i++] = ((pid / m) + 48);
		pid %= m;
		m /= 10; 
	}
	str[i] = '\0';
	return (str);
}

void	sig_handler(int signum)
{
	int	i;

	i = 0;
	while (i < 8 && bin[i])
		i++;
	if (signum == SIGUSR1)
		bin[i] = '0';
	else if (signum == SIGUSR2)
		bin[i] = '1';
	if (i == 7)
	{
		btoa();
		binres();
	}
}

int	main()
{
	pid_t	pid;
	char	*pid_str;
	
	pid = getpid();
	pid_str = ft_uitoa(pid);
	write(1, pid_str, (numlen(pid) + 1));
	write(1, "\n", 1);
	free(pid_str);
	binres();
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
