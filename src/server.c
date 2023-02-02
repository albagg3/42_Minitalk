/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:24:51 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/02 19:39:45 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "../lib/libft_src_printf/libft.h"
#include "../inc/errors.h"

int	g_bit;

char	*addchar_printstr(char res, char *buffer)
{
	char	str[2];
	char	*print;

	g_bit = 0;
	if (res == '\0')
	{
		if (ft_printf("%s\n", buffer) == -1)
			terminate(ERR_PRINT);
	}
	str[0] = res;
	str[1] = '\0';
	print = ft_strjoin(buffer, str);
	free(buffer);
	buffer = print;
	return (buffer);
}

int	print_counter(int counter)
{
	if (ft_printf("\r[%d]", ++counter) == -1)
		terminate(ERR_PRINT);
	return (counter);
}

void	sigaction_handler(int signal, siginfo_t *siginfo, void *context)
{
	static unsigned char	res;
	static char				*buffer;
	static int				pid;
	static int				counter = 0;

	(void) context;
	if (pid != siginfo->si_pid && siginfo->si_pid != 0)
	{
		if (ft_printf("[new_client]\n") == -1)
			terminate(ERR_PRINT);
		buffer = NULL;
		pid = siginfo->si_pid;
		buffer = ft_strdup("");
		counter = 0;
	}
	counter = print_counter(counter);
	if (signal == SIGUSR1)
		res = res | 1;
	g_bit++;
	usleep(50);
	if (kill(pid, SIGUSR1) == -1)
		terminate(ERR_SIG);
	if (g_bit == 8)
		buffer = addchar_printstr(res, buffer);
	res = res << 1;
}

//si se llama a la handler y se estaba ya ejecutando alguna funcion como
//open read o write y la función handle returns normal hay dos opciones. 
//Devolver un coigo de fallo EINTR o continuar con la ejecución del handler,
//si ponemos la flag SA_RESTART estamos diciendo que continúe en lugar de
//devolver un error

int	main(void)
{
	int					process;
	struct sigaction	signal;

	process = getpid();
	ft_printf("PID:[%d]\n", process);
	g_bit = 0;
	signal.sa_sigaction = sigaction_handler;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
	{
	}
}
