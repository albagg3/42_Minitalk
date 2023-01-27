/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:24:47 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/27 13:12:41 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_printf(long n)
{
	if (n < 0)
	{
		if (ft_putchar_printf('-') == -1)
			return (-1);
		if (ft_putnbr_printf(-n) == -1)
			return (-1);
	}
	else if (n >= 10)
	{
		if (ft_putnbr_printf(n / 10) == -1)
			return (-1);
		if (ft_putnbr_printf(n % 10) == -1)
			return (-1);
	}
	else
		if (ft_putchar_printf(n + '0') == -1)
			return (-1);
	return (ft_nbr_len(n));
}

int	ft_nbr_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
