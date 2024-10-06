/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:55 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/06 20:36:35 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_bin[8];

void	btoa(void)
{
	char	c;
	int		i;
	char	p;

	c = 0;
	i = 0;
	p = 6;
	while (g_bin[i] && i < 7)
	{
		if (g_bin[i] == '1')
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
		g_bin[i] = '\0';
}

char	*ft_uitoa(unsigned int pid)
{
	int		i;
	int		len;
	int		m;
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

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	int	i;

	(void) context;
	i = 0;
	while (i < 7 && g_bin[i])
		i++;
	if (signum == SIGUSR1)
		g_bin[i] = '0';
	else if (signum == SIGUSR2)
		g_bin[i] = '1';
	if (i == 6)
	{
		btoa();
		binres();
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	char				*pid_str;
	struct sigaction	sa;

	pid = getpid();
	pid_str = ft_uitoa(pid);
	write(1, pid_str, (numlen(pid) + 1));
	write(1, "\n", 1);
	free(pid_str);
	binres();
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
