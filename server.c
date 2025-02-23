/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:23:20 by aouaalla          #+#    #+#             */
/*   Updated: 2025/02/13 10:23:21 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_last_pid;

void	write_byte(int sig, siginfo_t *s, void *contest)
{
	static int	bit = 7;
	static char	octet = 0;

	(void)contest;
	if (s->si_pid != g_last_pid)
	{
		bit = 7;
		octet = 0;
	}
	g_last_pid = s->si_pid;
	if (sig == SIGUSR1)
		octet |= 1 << bit;
	bit--;
	if (bit == -1)
	{
		write(1, &octet, 1);
		bit = 7;
		octet = 0;
	}
	kill(s->si_pid, SIGUSR1);
}

void	sa_install(struct sigaction *sa_ptr)
{
	pid_t				pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	sigemptyset(&sa_ptr->sa_mask);
	sa_ptr->sa_flags = SA_SIGINFO;
	sa_ptr->sa_sigaction = write_byte;
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
