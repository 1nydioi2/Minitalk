/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:55 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/12 18:40:28 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_lenght = 0;

void	addchar(char c)
{
	static int	i = 0;
	static int	j = 0;
	static int	lenght = 0;
	static char	*str;

	if (g_lenght > 0)
		str[i++] = c;
	else if ((!g_lenght) && c == '!')
	{
		g_lenght = lenght;
		str = malloc(sizeof(char) * (g_lenght + 1));
		str[g_lenght] = '\0';
	}
	else
		lenght += (c * (power(10, j++)));
	if (i == g_lenght && i != 0)
	{
		write(1, str, lenght);
		lenght = 0;
		g_lenght = -1;
		i = 0;
		j = 0;
		free(str);
	}
}

void	btoa(char *bin)
{
	char	c;
	int		i;
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
	addchar(c);
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
	static int		i = 0;
	static char		bin[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	(void) context;
	if (signum == SIGUSR1)
		bin[i] = '0';
	else if (signum == SIGUSR2)
		bin[i] = '1';
	if (i++ == 7)
	{
		btoa(bin);
		strres(&bin, 9);
		i = 0;
	}
	if (g_lenght == -1)
	{
		kill(info->si_pid, SIGUSR2);
		g_lenght = 0;
		return ;
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
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
