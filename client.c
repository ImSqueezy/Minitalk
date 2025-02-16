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

void	data_send(int pid, char *message)
{
	int		i;
	int		j;
	int		bit;

	i = 0;
	while (message[i])
	{
		j = 7;
		while (j >= 0)
		{
			bit = (message[i] >> j) & MASK;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	char	*message;
	int		pid;
	
	// (void)argc;
	if (argc != 3)
		return (ft_printf("Syntax: %s pid message", argv[0]), 1);
	message = argv[2];
	pid = ft_atoi(argv[1]);
	data_send(pid, message);	
	return (0);
}
