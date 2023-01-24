/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:25:06 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/24 18:56:19 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	char_to_binary(int pid, char c)
{
	int bit;

	bit = 0;
	while(bit < 8)
	{
		if(c | 1 == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				Error the signal was not sent
		}		
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				Error the signal was not sent
		}
		//usleep
		c = c >> 1;
		bit++;
	}
}

int main (int argc, char **argv)
{
	int pid;

	if(argc != 3)
		terminate
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			char_to_binary(pid,argv[2][i]);
			i++;
		}
	}	


}
