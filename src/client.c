/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:25:06 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/02 19:38:33 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/libft_src_printf/libft.h"
#include "../inc/errors.h"

void	sig_handler(int signal)
{
	static int	counter = 0;

	if (signal)
	{
		if (ft_printf("\r[%d]", ++counter) == -1)
			terminate(ERR_PRINT);
	}
}

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
		pause();
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
	struct sigaction	sig;

	sig.sa_handler = sig_handler;
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
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
