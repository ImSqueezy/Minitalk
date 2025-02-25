/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:00:33 by aouaalla          #+#    #+#             */
/*   Updated: 2025/02/20 14:00:34 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define MASK 1
# define PID_ERROR "Error: No such process with the following ID\n"
# define PID_ERROR1 "Error: pid enterance is Invalid!\n\
(Syntax: %s process_id message)\n"
# define INVALID_ARGS_N "Error: Invalid number of args!\n\
(Syntax: %s process_id message)\n"
# define EMPTY_ARG "Invalid Arg: Empty strings can not be processed!\n"
# define ACKNOWLEDGEMENT_MESSAGE "The message has been SUCCESSFULLY received!\n"
# define NEGATIVE_PID_ERROR "Error: The pid can not be negative!\n\
(This error might occur in case of an overflow or\
a negative pid was enterance)\n"
# include <signal.h>
# include "printf/ft_printf.h"
# include "Libft/libft.h"

typedef struct s_info
{
	int		byte_sequence;
	char	bytes[4];
	char	octet;
	int		current_byte;
	int		current_bit;
	int		last_pid;
}	t_info;

typedef struct s_cinfo
{
	int	flag;
	int	pid;
}	t_cinfo;

void	expected_bytes(t_info *g_info);
void	byte_writer(t_info *g_info);
void	pid_checker(siginfo_t *ptr, t_info *g_info);

#endif
