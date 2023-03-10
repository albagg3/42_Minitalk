/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:25:06 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/09 13:27:33 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/libft_src_printf/libft.h"
#include "../inc/errors.h"

int	char_to_binary(int pid, char c)
{
	int	bit;
	int	signal;

	bit = 0;
	while (bit < 8)
	{
		if ((c & 128))
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			terminate(ERR_SIG);
			return (1);
		}
		usleep(300);
		bit++;
		c = c << 1;
	}
	return (1);
}

int	check_pid(char *str_pid)
{
	int	i;
	int	pid;

	i = 0;
	while (str_pid[i] != '\0')
	{
		if (ft_isalpha(str_pid[i]))
			terminate(ERR_ALPH);
		i++;
	}
	pid = ft_atoi(str_pid);
	if (pid <= 0)
		terminate(ERR_PID);
	return (pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;

	i = 0;
	if (argc != 3)
		return (0);
	else
	{
		pid = check_pid(argv[1]);
		if (pid <= 0)
			terminate(ERR_PID);
		while (argv[2][i])
		{
			char_to_binary(pid, argv[2][i]);
			i++;
		}
		char_to_binary(pid, 0);
	}
}
