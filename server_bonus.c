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

void	expected_bytes(unsigned char octet)
{
	if ((octet & 0x80) == 0)
		g_info.byte_sequence = 1;
	if ((octet & 0xE0) == 0xC0)
		g_info.byte_sequence = 2;
	if ((octet & 0xF0) == 0xE0)
		g_info.byte_sequence = 3;
	if ((octet & 0xF8) == 0xF0)
		g_info.byte_sequence = 4;
}

void	byte_writer(void)
{
	write(1, &g_info.bytes, g_info.byte_sequence);
	ft_memset(&g_info, 0, sizeof(t_info) - sizeof(int));
}

void	data_receiver(int sig, siginfo_t *s, void *contest)
{
	(void)contest;
	if (s->si_pid != g_info.last_pid)
	{
		ft_memset(&g_info, 0, sizeof(t_info));
		g_info.current_bit = 7;
		g_info.last_pid = s->si_pid;
	}
	if (sig == SIGUSR1)
		g_info.octet |= 1 << g_info.current_bit;
	g_info.current_bit--;
	if (g_info.current_bit == -1)
	{
		if (g_info.octet == '\0')
			return (kill(s->si_pid, SIGUSR2), exit(0));
		if (g_info.current_byte == 0)
			expected_bytes(g_info.octet);
		g_info.bytes[g_info.current_byte] = g_info.octet;
		g_info.current_byte++;
		if (g_info.current_byte == g_info.byte_sequence)
			byte_writer();
		g_info.octet = 0;
		g_info.current_bit = 7;
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
