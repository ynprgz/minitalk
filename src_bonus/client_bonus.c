/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:37:03 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/05 23:30:34 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#define ENDOFMESSAGE '\n'

void	acknowledge_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Received 1\n");
	else if (signal == SIGUSR2)
		ft_printf("Received 0\n");
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	signal(SIGUSR1, acknowledge_signal);
	signal(SIGUSR2, acknowledge_signal);
	if (argc != 3)
	{
		write(1, "Usage: ./client_bonus <server_pid> <message>\n", 45);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	send_char(server_pid, ENDOFMESSAGE);
	return (0);
}

// int bit helps us go through all the bits that represent char c
// A char is always 1 byte(8 bits). An int is platform-depedent, but the C
// standard gurantees that an int is at least 16 bits.
//
// usleep(100) enters a 100 microseconds delay so it ensures the signal is
// procesed by the operating system and also reduce the possibility of signal
// overlapping
//
// MSB(Most Significant Bit), LSB (Least Significant Bit).
