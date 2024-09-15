/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:57:38 by dloisel           #+#    #+#             */
/*   Updated: 2024/07/02 13:04:50 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

void	ft_bin_to_char(int signal, char *c)
{
	if (signal == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signal == SIGUSR2)
		*c <<= 1;
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static int		client_pid;
	static char		c;
	static int		i;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	ft_bin_to_char(signal, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf(YELLOW"The process ID is :"RESET);
	ft_printf(GREEN" %d\n"RESET, getpid());
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	action.sa_sigaction = sig_handler;
	if ((sigaction(SIGUSR1, &action, NULL)) == -1)
		return (ft_printf("Error SIGUSR1\n"), 1);
	if ((sigaction(SIGUSR2, &action, NULL)) == -1)
		return (ft_printf("Error SIGUSR2\n"), 1);
	while (1)
		pause();
	return (0);
}
