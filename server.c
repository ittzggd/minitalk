#include<unistd.h>
#include<signal.h>
#include<stdio.h>

void	handler(int signo);
void	ft_putnbr(int nb);

int main(void)
{
	int		pid;

	pid = getpid();
	printf("pid : %d\n", pid);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while(1)
	{
		pause();
	}
	return (0);
}

void handler(int signo)
{
	static int i = 0;
	static int c = 0;

	if(signo == SIGUSR1) // sigusr1 == 0
	{
//		printf("0");
//		printf("%d\n", i);
		c *= 2;
	}
	else
	{
//		printf("1");
//		printf("%d\n", i);
		c *= 2;
		c++;
	}
	i++;
	if(i == 8) //  초기화 
	{
//		printf("%d\n", c);
		if(write(1, &c, 1) == -1)
			printf("error\n");
		i = 0;
		c = 0;
	}
}


