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

int main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Invalid number of args!"), 1);
	if (kill(ft_atoi(argv[1]), SIGUSR1) != 0)
		return (ft_printf("The pid is not valid!"), 1);
	return (0);
}
