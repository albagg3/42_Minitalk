/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:24:51 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/24 18:56:17 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

}
