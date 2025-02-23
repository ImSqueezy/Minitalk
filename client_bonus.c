/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:00:14 by aouaalla          #+#    #+#             */
/*   Updated: 2025/02/20 14:00:15 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_cinfo	g_info;

int	args_check(int ac, char **av)
{
	if (ac != 3)
		return (ft_printf("%s", INVALID_ARGS_N), 0);
	if (!*av[1] || !*av[2])
		return (ft_printf("%s", EMPTY_ARG), 0);
	g_info.flag = 1;
	g_info.pid = ft_atoi(av[1]);
	if (g_info.pid < 0)
		return (ft_printf("%s", NEGATIVE_PID_ERROR), 0);
	else if (g_info.pid == 0)
		return (ft_printf("%s", PID_ERROR), 0);
	return (1);
}

void	data_sender(char octet)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if ((octet >> i) & MASK)
		{
			if (kill(g_info.pid, SIGUSR1) != 0)
				return (ft_printf("%s", PID_ERROR), exit(0));
		}
		else
		{
			if (kill(g_info.pid, SIGUSR2) != 0)
				return (ft_printf("%s", PID_ERROR), exit(0));
		}
		i--;
		while (g_info.flag)
			usleep(5);
		g_info.flag = 1;
	}
}

void	notifier(int sig)
{
	if (sig == SIGUSR1)
		g_info.flag = 0;
	else if (sig == SIGUSR2)
	{
		ft_printf("%s", ACKNOWLEDGEMENT_MESSAGE);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	char				*message;
	unsigned int		byte;

	if (!args_check(argc, argv))
		return (1);
	signal(SIGUSR1, notifier);
	signal(SIGUSR2, notifier);
	message = argv[2];
	byte = -1;
	while (message[++byte])
		data_sender(message[byte]);
	data_sender('\0');
	return (0);
}
