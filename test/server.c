#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void	post(int pid, int idx)
{
	if (idx == 1)
	{
		printf("1");
		kill(pid, SIGUSR1);
	}
	else if (idx == 0)
	{
		printf("0");
		kill(pid, SIGUSR2);
	}
	else
	{
		printf("\n");
		kill(pid, 0);
	}
	usleep(1000);
}

void	conv_and_post(int pid, int c, int num)
{
	if (!c)
	{
		while (num != 8)
		{
			post(pid, 0);
			num++;
		}
		return ;
	}
	else
	{
		conv_and_post(pid, c / 2, ++num);
		post(pid, c % 2);
	}
}
void	post_office(int pid, char *str)
{
	int		c;
	int		num;
	int		idx;

	c = 0;
	idx = -1;
	while (str[++idx])
	{
		num = 0;
		c = (int)str[idx];
		conv_and_post(pid, c, num);
		post(pid, -1);
	}
}

int		main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	else
	{
		printf("PID : %s, Massage : %s\n", argv[1], argv[2]);
		post_office(atoi(argv[1]), argv[2]);
	}
}
