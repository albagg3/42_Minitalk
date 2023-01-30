/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:25:06 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/30 20:24:55 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/libft_src_printf/libft.h"

/*int	malloc_signals(int pid, char *str)
{
	int	 i;
	while(str[i] != NULL)
	{
		if(kill(pid, SIGUSR1))
			return(0);
		i++;
	}
	kill(pid,SIGUSR2);
	return(0);
}*/


int	char_to_binary(int pid, char c)
{
	int bit;
	bit = 0;

while(bit < 8)
{

	if((c & 128))
	{
		if (kill(pid, SIGUSR1) == -1)
			return (0);
		//	Error the signal was not sent
	}		
	else
	{
	//	printf("sigurs2\n");
		if (kill(pid, SIGUSR2) == -1)
			return(0);
		//	Error the signal was not sent
	}
	usleep(300);//pause();
	bit++;
	c = c << 1;
	}
	return(1);
}

int main (int argc, char **argv)
{
	int pid;
	int i;
	
	i = 0;
	if (argc != 3)
		return(0);
	//	terminate
	
	else
	{
		pid = ft_atoi(argv[1]);
//		malloc_signals(pid, argv[2]);
		while (argv[2][i])
		{
		//	printf("argumento:%c\n", argv[2][i]);
			char_to_binary(pid,argv[2][i]);
			i++;
		}
		char_to_binary(pid, 0);
	}	


}
