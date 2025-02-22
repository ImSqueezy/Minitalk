/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:19:21 by aouaalla          #+#    #+#             */
/*   Updated: 2025/02/13 10:19:23 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_flag;

int	args_check(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Invalid number of args!\n(Syntax: %s process_id message)\n",
			av[0]);
		return (0);
	}
	return (1);
}

void	data_send(int pid, unsigned int byte, char *message)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		while (g_flag)
			usleep(1);
		g_flag = 1;
		if ((message[byte] >> i) & MASK)
		{
			if (kill(pid, SIGUSR1) != 0)
				return (ft_printf("The pid is incorrect!\n"), exit(0));
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
				return (ft_printf("The pid is incorrect!\n"), exit(0));
		}
		i--;
	}
}

void notifier(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 0;
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	unsigned int		byte;
	struct sigaction	ts;

	if (!args_check(argc, argv))
		return (1);
	ts.sa_flags = 0;
	ts.sa_handler = notifier;
	sigaction(SIGUSR1, &ts, NULL);
	message = argv[2];
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("The pid is incorrect!\n"));
	byte = -1;
	while (message[++byte])
		data_send(pid, byte, message);
	return (0);
}
