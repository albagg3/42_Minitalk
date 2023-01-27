/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_string                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:23:32 by albagarc          #+#    #+#             */
/*   Updated: 2023/01/27 13:09:43 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_printf(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr_printf(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (s[len] != '\0')
	{
		if (ft_putchar_printf(s[len]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_print_character(int n)
{
	if (ft_putchar_printf(n) == -1)
		return (-1);
	return (1);
}

int	ft_print_string(char *str)
{
	return (ft_putstr_printf(str));
}
