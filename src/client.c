/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:36:16 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/05 22:25:04 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#define ENDOFMESSAGE '\n'

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

	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: ./client <server_pid> <message>\n", 39);
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
