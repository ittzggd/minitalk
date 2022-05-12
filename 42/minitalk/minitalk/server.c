/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:38:47 by hejang            #+#    #+#             */
/*   Updated: 2022/05/12 10:44:13 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int		pid;

	pid = getpid();
	printf("pid : %d\n", pid);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
	{
		pause();
	}
	return (0);
}

void	handler(int signo)
{
	static int	i = 0;
	static int	c = 0;

	if (signo == SIGUSR1)
		c *= 2;
	else
	{
		c *= 2;
		c++;
	}
	i++;
	if (i == 8)
	{
		if (write(1, &c, 1) == -1)
			printf("error\n");
		i = 0;
		c = 0;
	}
}
