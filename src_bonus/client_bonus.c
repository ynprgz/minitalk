/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:37:03 by yaperalt          #+#    #+#             */
/*   Updated: 2025/01/27 02:40:19 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Usage: ./client_bonus <server_pid> <message>\n", 44);
		return (1);
	}
}
