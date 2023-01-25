/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:24:51 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/25 13:27:54 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void sig_handler(int signal)
{
	char	res;
	int		bit;

	res = 0;
	bit = 0;
	while (bit < 8)
	{
		printf("entra\n");
		if (signal == SIGUSR1)
			res = res | 1;
		if (signal == SIGUSR2)
			res = res | 0;
		res = res << 1;
		bit++;
	}
	printf("resultado = %c\n", res);

}

int main(){
	int process;
	process = getpid();
	printf("PID:[%d]\n", process);
	struct sigaction signal;

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
