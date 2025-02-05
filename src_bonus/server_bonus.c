/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:37:01 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/05 23:30:14 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// "1 << i" creates a mask with a 1 at the i-th position.
// "character | (1 << i)" sets the i-th bit of character to 1.
void	signal_handler(int sig_num, siginfo_t *info, void *context)
{
	static int	i;
	static int	character;

	(void)context;
	if (sig_num == SIGUSR1)
		character = character | (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar(character);
		i = 0;
		character = 0;
	}
	if (sig_num == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sig_num == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

// struct sigaction (signal handler)
//
// sa.sigaction = &signal_handler a pointer pointing to the function that
// is going to handle the signal
//
// sa.sa_flags Control the behavior of the handler, to receive additional info
//
// sigemptyset(&sa.samask) doesnt block any signal during the execution
//
// sigaction(SIGUSR1, &sa, NULL) configure the action when the process
// receives the signal to  invoke signal_handler
int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_printf("Signal pid: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
