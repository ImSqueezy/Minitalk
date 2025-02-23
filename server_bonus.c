/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:00:25 by aouaalla          #+#    #+#             */
/*   Updated: 2025/02/20 14:00:26 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_info	g_info;

void	data_receiver(int sig, siginfo_t *ptr, void *contest)
{
	(void)contest;
	pid_checker(ptr, &g_info);
	if (sig == SIGUSR1)
		g_info.octet |= 1 << g_info.current_bit;
	g_info.current_bit--;
	if (g_info.current_bit == -1)
	{
		if (g_info.octet == 0)
		{
			kill(ptr->si_pid, SIGUSR2);
			return ;
		}
		if (g_info.current_byte == 0)
			expected_bytes(&g_info);
		g_info.bytes[g_info.current_byte] = g_info.octet;
		g_info.current_byte++;
		if (g_info.current_byte == g_info.byte_sequence)
			byte_writer(&g_info);
		g_info.octet = 0;
		g_info.current_bit = 7;
	}
	kill(ptr->si_pid, SIGUSR1);
}

void	sa_install(struct sigaction *sa_ptr)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	sigemptyset(&sa_ptr->sa_mask);
	sa_ptr->sa_flags = SA_SIGINFO;
	sa_ptr->sa_sigaction = data_receiver;
}

int	main(void)
{
	struct sigaction	sa;

	sa_install(&sa);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
