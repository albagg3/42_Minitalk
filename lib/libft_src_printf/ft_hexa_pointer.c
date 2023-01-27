/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:14:02 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/27 13:09:03 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_lower(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (ft_hexa_lower(n / 16) == -1)
			return (-1);
	}
	if (ft_putchar_printf(base[n % 16]) == -1)
		return (-1);
	return (ft_hexa_len(n));
}

int	ft_hexa_upper(unsigned long n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (ft_hexa_upper(n / 16) == -1)
			return (-1);
	}
	if (ft_putchar_printf(base[n % 16]) == -1)
		return (-1);
	return (ft_hexa_len(n));
}

int	ft_hexa_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len ++;
		n = n / 16;
	}
	return (len);
}

int	ft_pointer(unsigned long long n)
{
	int	len;

	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	len += ft_hexa_lower(n);
	return (len);
}
