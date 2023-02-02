/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:24:51 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/02 17:48:54 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "../lib/libft_src_printf/libft.h"
int		g_bit;


char	*addchar_printstr(char res, char *buffer)
{
	char	str[2];
	char	*print;
	g_bit = 0;
	if(res == '\0')
	{
		ft_printf("%s\n",buffer);
//		free(buffer);
//		exit(0);
	}
	str[0] = res;
	str[1] = '\0';
	print = ft_strjoin(buffer, str);
	free(buffer);
	buffer = print;
	return (buffer);
}

void sigaction_handler(int signal, siginfo_t *siginfo,void  *context)
{
	(void) context;
	static unsigned char	res;
	static char				*buffer;
	static int				pid;
	static int				counter = 0;


	if(pid != siginfo->si_pid && siginfo->si_pid != 0)
	
	{
		ft_printf("[new_client]\n, %d\n", siginfo->si_pid);
//		free(buffer);
		buffer = NULL;
		pid = siginfo->si_pid;
		buffer = ft_strdup("");
		counter = 0;
	}
	counter++;
	ft_printf("\r[%d]",counter);
	if (signal == SIGUSR1)
		res = res | 1;
	g_bit++;
	usleep(50);
	kill(pid, SIGUSR1);
	if(g_bit == 8)
	{
		buffer = addchar_printstr(res,buffer);
	}
	res = res << 1;
}

//si se llama a la handler y se estaba ya ejecutando alguna funcion ocmo open read o write y la función handle returns normal hay dos opciones. Devolver un coigo de fallo EINTR o continuar con la ejecución del handler, si ponemos la flag SA_RESTART estamos diciendo que continúe en lugar de devolver un error

int main()
{
	int process;
	process = getpid();
	ft_printf("PID:[%d]\n", process);
	struct sigaction signal;

	g_bit = 0;
	signal.sa_sigaction = sigaction_handler;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while(1)
	{
		
	}
}
