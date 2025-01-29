/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:36:25 by yaperalt          #+#    #+#             */
/*   Updated: 2025/01/29 00:37:29 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <signal.h>

// "1 << i" creates a mask with a 1 at the i-th position.
// "character | (1 << i)" sets the i-th bit of character to 1.
void	signal_handler(int sig_num)
{
	static int	i;
	static int	character;

	if (sig_num == SIGUSR1)
		character = character | (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar(character);
		i = 0;
		character = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Signal pid: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
