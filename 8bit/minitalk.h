/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:14:41 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/09 17:06:09 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

int		power(int x, int y);
int		numlen(unsigned int i);
void	strres(char (*str)[], int lenght);
int		ft_atoui(char s[]);
int		is_number(char str[]);
int		ft_strlen(char *str);

#endif
