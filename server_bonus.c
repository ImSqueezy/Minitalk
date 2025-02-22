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

typedef struct s_info
{
	int		byte_sequence;
	char	bytes[4];
	char	octet;
	int		current_byte;
	int		current_bit;
	int		last_pid;
}	t_info;

t_info	info;

void	expected_bytes(t_info *info, unsigned char octet)
{
	if (info->byte_sequence)
		return ;
	if ((octet & 0x80) == 0)
		info->byte_sequence = 1;
	if ((octet & 0xE0) == 0xC0)
		info->byte_sequence = 2;
	if ((octet & 0xF0) == 0xE0)
		info->byte_sequence = 3;
	if ((octet & 0xF8) == 0xF0)
		info->byte_sequence = 4;
}

void	write_byte(int sig, siginfo_t *s, void *contest)
{
	(void)contest;

	if (s->si_pid != info.last_pid)
	{
		ft_memset(&info, 0, sizeof(t_info));
		info.current_bit = 7;
		info.last_pid = s->si_pid;
	}
	if (sig == SIGUSR1)
		info.octet |= 1 << info.current_bit;
	info.current_bit--;
	if (info.current_bit == -1)
	{
		if (info.octet == '\0')
		{
			int a = kill(s->si_pid, SIGUSR2);
			ft_printf ("a ::  %d \n", a);
			return ;
		}
		if (info.current_byte == 0)
			expected_bytes(&info, info.octet);
		info.bytes[info.current_byte] = info.octet;
		info.current_byte++;
		if (info.current_byte == info.byte_sequence)
		{
			write(1, &info.bytes, info.byte_sequence);
			ft_memset(&info, 0, sizeof(t_info) - sizeof(int));
		}
		info.octet = 0;
		info.current_bit = 7;
	}
	kill(s->si_pid, SIGUSR1);
}

void	sa_install(struct sigaction *sa_ptr)
{
	pid_t				pid;

	info.byte_sequence = 0;
	info.current_byte = 0;
	info.current_bit = 7;
	info.last_pid = 0;
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

// #include <stdio.h>
// void	write_bits(int *bit, char *octet, siginfo_t *sig_info)
// {
// 	// printf("\n%d", *bit);
// 	if (*bit == -1)
// 	{
// 		write(1, octet, 1);
// 		if (*octet == '\0')
// 			kill(sig_info->si_pid, SIGUSR2);
// 		*bit = 7;
// 		*octet = 0;
// 	}
// 	kill(sig_info->si_pid, SIGUSR1);
// }

// void	handler(int sig, siginfo_t *sig_info, void *ptr)
// {
// 	static int	bit;
// 	static char octet;
// 	(void)octet;
// 	(void)bit;
// 	(void)ptr;

// 	bit = 7;
// 	octet = 0;
// 	if (sig_info->si_pid != info.last_pid)
// 	{
// 		bit = 7;
// 		octet = 0;
// 	}
// 	info.last_pid = sig_info->si_pid;
// 	printf("here");
// 	if (sig == SIGUSR1)
// 		printf("sigusr1");
// 	if (sig == SIGUSR2)
// 		printf("sigusr2");
// 	// bit--;
// 	// printf("\n%d", bit);
// 	// if (bit == -1)
// 	// 	info.current_byte++;
// 	// write_bits(&bit, &octet, sig_info);
// }

// void handerl_initializer(struct sigaction *sa_ptr)
// {
// 	pid_t				pid;

// 	pid = getpid();
// 	ft_printf("%d\n", pid);
// 	sigemptyset(&sa_ptr->sa_mask);
// 	sa_ptr->sa_flags = SA_SIGINFO;
// 	sa_ptr->sa_sigaction = handler;
// }

// int main()
// {
// 	struct sigaction sigact;

// 	handerl_initializer(&sigact);
// 	sigaction(SIGUSR1, &sigact, NULL);
// 	sigaction(SIGUSR2, &sigact, NULL);
// 	while (1)
// 		pause();
// 	return (0);
// }
