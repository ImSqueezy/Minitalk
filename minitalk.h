/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:02:31 by aouaalla          #+#    #+#             */
/*   Updated: 2025/02/13 11:02:39 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define MASK 1
# define PID_ERROR "Error: No such process with the following ID\n"
# define PID_ERROR1 "Error: pid enterance is Invalid!\n\
(Syntax: %s process_id message)\n"
# define INVALID_ARGS_N "Error: Invalid number of args!\n\
(Syntax: %s process_id message)\n"
# define EMPTY_ARG "Invalid Arg: Empty strings can not be processed!\n"
# define NEGATIVE_PID_ERROR "Error: The pid can not be negative!\n\
(This error might occur in case of an overflow or\
a negative pid was enterance)\n"
# include <signal.h>
# include <unistd.h>
# include "printf/ft_printf.h"
# include "Libft/libft.h"

typedef struct s_cinfo
{
	int	flag;
	int	pid;
}	t_cinfo;

#endif
