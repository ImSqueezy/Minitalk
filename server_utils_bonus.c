/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:12:18 by aouaalla          #+#    #+#             */
/*   Updated: 2025/02/23 14:12:20 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	expected_bytes(t_info *g_info)
{
	if ((g_info->octet & 0x80) == 0)
		g_info->byte_sequence = 1;
	if ((g_info->octet & 0xE0) == 0xC0)
		g_info->byte_sequence = 2;
	if ((g_info->octet & 0xF0) == 0xE0)
		g_info->byte_sequence = 3;
	if ((g_info->octet & 0xF8) == 0xF0)
		g_info->byte_sequence = 4;
}

void	byte_writer(t_info *g_info)
{
	write(1, &g_info->bytes, g_info->byte_sequence);
	ft_memset(g_info, 0, sizeof(t_info) - sizeof(int));
}

void	pid_checker(siginfo_t *ptr, t_info *g_info)
{
	if (ptr->si_pid != g_info->last_pid)
	{
		ft_memset(g_info, 0, sizeof(t_info));
		g_info->current_bit = 7;
		g_info->last_pid = ptr->si_pid;
	}
}
