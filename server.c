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

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)sig;
	ft_printf("received a signal!\n");
	if (sig == SIGUSR1)
		ft_printf("im ISG1");
	else
		ft_printf("im SIG2");
}

int main()
{
	int		i;
	pid_t	pid;
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("%d", pid);

	i = 0;
	while (1)
		i++;
	return (0);
}
