/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:24:51 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/27 13:37:34 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "../lib/libft_src_printf/libft.h"
int		g_bit;


void sig_handler(int signal)
{
	static unsigned char	res;
 
	if (signal == SIGUSR1)
	{
		res = res | 1;
	}

	g_bit++;
	if(g_bit == 8)
	{
		write(1, &res, 1);
		g_bit = 0;
	}
	res = res << 1;

}

int main(){
	int process;
	process = getpid();
	ft_printf("PID:[%d]\n", process);
	struct sigaction signal;

	g_bit = 0;
	signal.sa_handler = sig_handler;
//si se llama a la handler y se estaba ya ejecutando alguna funcion ocmo open read o write y la función handle returns normal hay dos opciones. Devolver un coigo de fallo EINTR o continuar con la ejecución del handler, si ponemos la flag SA_RESTART estamos diciendo que continúe en lugar de devolver un error
	signal.sa_flags = SA_RESTART;	
	//es sigaction una escucha de señales?
	
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while(1)
	{
		pause();
	}

}
