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

int	g_pid;

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

void	data_send(unsigned int byte, char *message)
{
	int		i;
	int		bit; // debut

	i = 7;
	while (i >= 0)
	{
		if ((bit = (message[byte] >> i) & MASK))
		{
			if (kill(g_pid, SIGUSR1) != 0)
				return (ft_printf("The pid is incorrect.\n"), exit(0));
			// ft_printf("%d", bit);
		}
		else
		{
			if (kill(g_pid, SIGUSR2) != 0)
				return (ft_printf("The pid is incorrect.\n"), exit(0));
			// ft_printf("%d", bit);
		}
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	char	*message;

	if (!args_check(argc, argv))
		return (1);
	message = argv[2];
	g_pid = ft_atoi(argv[1]);
	ft_striteri(message, data_send);
	return (0);
}
