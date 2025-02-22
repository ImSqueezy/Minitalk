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
// void	data_sender(int pid, unsigned char octet);

// int	g_flag;

// int	arg_check(int ac, char **av)
// {
// 	if (ac != 3)
// 	{
// 		ft_printf("Invalid number of args!\n(Syntax: %s process_id message)\n",
// 		av[0]);
// 		return (0);
// 	}
// 	if (!av[1] || !av[2])
// 		return (ft_printf("The message might be empty!"), 0);
// 	return (ft_atoi(av[1]));
// }

// void	handler(int sig)
// {
// 	if (sig == SIGUSR1)
// 		g_flag = 0;
// 	else
// 	{
// 		ft_printf("The message has been delivered successfully!");
// 		exit(0);
// 	}
// }

// void	handler_initializer(struct sigaction *sig, int pid, char *message)
// {
// 	int	byte;

// 	sig->sa_flags = 0;
// 	sig->sa_handler = handler;
// 	if (sigaction(SIGUSR1, sig, NULL) == -1)
// 		return (ft_printf("The handler failed to be initialized!"), exit(0));
// 	if (sigaction(SIGUSR2, sig, NULL))
// 		return (ft_printf("The handler failed to be initialized!"), exit(0));
// 	byte = -1;
// 	while (message[++byte])
// 		data_sender(pid, message[byte]);
	
// }

// void	data_sender(int pid, unsigned char octet)
// {
// 	int		i;

// 	i = 7;
// 	while (i >= 0)
// 	{
// 		while (g_flag)
// 			usleep(1);
// 		g_flag = 1;
// 		if ((octet >> i) & ONE_BIT_MASK)
// 		{
// 			if (kill(pid, SIGUSR1) != 0)
// 				return (ft_printf("The pid is incorrect!\n"), exit(0));
// 			else
// 				ft_printf("1");
// 		}
// 		else
// 		{
// 			if (kill(pid, SIGUSR2) != 0)
// 				return (ft_printf("The pid is incorrect!\n"), exit(0));
// 			else
// 				ft_printf("0");
// 		}
// 		i--;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	int				pid;
// 	struct sigaction sigact;

// 	pid = arg_check(argc, argv);
// 	if (pid <= 0)
// 		return (ft_printf("The pid is incorrect!"), 1);
// 	handler_initializer(&sigact, pid, argv[2]);
// 	return (0);
// }

static int	g_flag = 1;
#define MASK 1

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
		while (g_flag)
			usleep(10);
		g_flag = 1;
	}
}

void notifier(int sig)
{
	// ft_printf("handler\n");
	if (sig == SIGUSR1)
	{
		ft_printf("p");
		g_flag = 0;
	}
	// {
	// 	ft_printf("%d", g_flag);
	// }
	else if (sig == SIGUSR2)
		ft_printf("MESSAGE HAS BEEN RECEIVED!");
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	unsigned int		byte;
	// struct sigaction	ts;

	if (!args_check(argc, argv))
		return (1);
	signal(SIGUSR1, notifier);
	signal(SIGUSR2, notifier);
	// ts.sa_flags = 0;
	// ts.sa_handler = notifier;
	// sigaction(SIGUSR1);
	// sigaction(SIGUSR2);
	message = argv[2];
	pid = ft_atoi(argv[1]); if (pid <= 0)
		return (ft_printf("The pid is incorrect!\n"));
	byte = -1;
	while (message[++byte])
		data_send(pid, byte, message);
	return (0);
}