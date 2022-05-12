#include<signal.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void	interrupHandler(int sig)
{
	printf("this program will be exited in 3 seconds..\n");
	sleep(3);
	exit(0);
}

int	main()
{
	signal(SIGINT, interrupHandler);
	printf("input CTRLC\n");
	for(int	i = 0; i < 15; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}
}
