/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:36:11 by hejang            #+#    #+#             */
/*   Updated: 2022/05/12 10:44:36 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	main(int argc, char	**argv)
{
	int	pid;
	int	i;
	int	j;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		i = 0;
		j = 128;
		if (pid < 0 || pid > 100000)
			printf("please check pid again\n");
		else
		{
			printf("pid : %d\n", pid);
			printf("message : %s\n", argv[2]);
			while (argv[2][i] != '\0')
			{
				send_char(pid, argv[2][i], j);
				i++;
			}
			send_char(pid, 10, j);
		}
	}
	else
		write(1, "need pid and message!\n", 33);
}

void	send_char(int pid, char c, int i)
{
	if (i > 1)
	{
		send_char(pid, c / 2, i / 2);
	}
	send_bit(pid, c % 2);
	printf("%d\n", c % 2);
}

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	usleep(100);
}
