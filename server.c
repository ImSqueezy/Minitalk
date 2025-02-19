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

void	print_bits(unsigned char octet) // debug
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

void	write_byte(int sig, siginfo_t *s, void *contest)
{
	(void)s;
	(void)contest;
	static int	bit = 7;
	static char	c = 0;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit == 0)
	{
		write(1, &c, 1);
		bit = 7;
		c = 0;
	}
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
