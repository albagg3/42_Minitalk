/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:13:35 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/27 13:10:57 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_identify_format(va_list arg, char c)
{
	if (c == 'c')
		return (ft_print_character(va_arg(arg, int)));
	if (c == 's')
		return (ft_print_string(va_arg(arg, char *)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr_printf(va_arg(arg, int)));
	if (c == 'u')
		return (ft_putnbr_printf(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_hexa_lower(va_arg(arg, unsigned int)));
	if (c == 'X')
		return (ft_hexa_upper(va_arg(arg, unsigned int)));
	if (c == '%')
		return (ft_putchar_printf('%'));
	if (c == 'p')
		return (ft_pointer(va_arg(arg, unsigned long long)));
	return (0);
}

int	ft_protect_printf(const char *str, va_list arg, int len)
{
	int	i;
	int	result;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result = ft_identify_format(arg, str[i + 1]);
			if (result == -1)
				return (-1);
			len += result;
			i++;
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	arg;

	len = 0;
	va_start (arg, str);
	len = ft_protect_printf(str, arg, len);
	va_end (arg);
	return (len);
}
