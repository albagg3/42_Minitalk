/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:21:49 by albagarc          #+#    #+#             */
/*   Updated: 2023/02/02 19:35:40 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_SIG "Error: The signal failed to sent."
# define ERR_PRINT "Error : ft_printf failed."
# define ERR_PID "Error : The process ID (pid) should be greater than one."
# define ERR_ALPH "Error : The process ID (pid) should be a number."

void	terminate(char *s);

#endif
