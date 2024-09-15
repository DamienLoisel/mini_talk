/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:10:41 by dloisel           #+#    #+#             */
/*   Updated: 2024/07/10 17:59:42 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

static int	g_receiver;

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	(void)info;
	g_receiver = 1;
	if (signal == SIGUSR2)
		i++;
	else if (signal == SIGUSR1)
		ft_printf("Num of bytes received : %d\n", i / 8);
}

int	ft_char_to_bin(char c, int server_pid)
{
	int	itr;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		itr = 0;
		if ((c >> bit_index) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (itr == 50)
			{
				ft_printf("Server doesn't respond");
				exit(1);
			}
			itr++;
			usleep(100);
		}
		g_receiver = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	int					i;
	int					server_pid;

	i = 0;
	if (argc != 3)
		return (ft_printf("You need 2 arguments : 'PID' 'MESSAGE'"));
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (ft_printf(RED"Invalid PID"RESET), 1);
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	action.sa_sigaction = sig_handler;
	if ((sigaction(SIGUSR1, &action, NULL)) == -1)
		return (ft_printf("Error SIGUSR1\n"), 1);
	if ((sigaction(SIGUSR2, &action, NULL)) == -1)
		return (ft_printf("Error SIGUSR2\n"), 1);
	while (argv[2][i])
	{
		ft_char_to_bin(argv[2][i], server_pid);
		i++;
	}
	ft_char_to_bin('\0', server_pid);
	return (0);
}
