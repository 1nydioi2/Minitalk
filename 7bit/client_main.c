/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:30:38 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/09 17:10:27 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_aor = 0;

void	char_to_sig(char c, pid_t pid)
{
	int	i;

	i = 6;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		while (g_aor == 0)
			usleep(1);
		g_aor = 0;
	}
}

void	dig_to_sig(int num, pid_t pid)
{
	int	i;
	int	digit;

	while (num)
	{
		digit = num % 10;
		i = 6;
		while (i >= 0)
		{
			if ((digit >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			while (g_aor == 0)
				usleep(1);
			g_aor = 0;
		}
		num /= 10;
	}
}

void	received(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		if (signum == SIGUSR2)
			write(1, "Server told us he fully received the message :)\n", 49);
		g_aor = 1;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	int		lenght;

	if (argc != 3)
		return (write(1, "Wrong argument amount\n", 23));
	if (is_number(argv[1]))
		return (write(1, "PID format not recognized\n", 27));
	str = argv[2];
	pid = ft_atoui(argv[1]);
	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	lenght = ft_strlen(str);
	dig_to_sig(lenght, pid);
	char_to_sig('!', pid);
	while (*str)
	{
		char_to_sig(*str, pid);
		str++;
	}
	return (0);
}
