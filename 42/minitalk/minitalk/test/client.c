#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void	handler(int signo, siginfo_t *info, void *context)
{
	if (signo == SIGUSR1)
		write(1, "1", 1);
	else if (signo == SIGUSR2)
		write(1, "0", 1);
}

int	main(void)
{
	struct sigaction act1;
	printf("pid : %d\n", getpid());

	act1.sa_sigaction = handler;
	act1.sa_flags = SA_SIGINFO;
	if(sigaction(SIGUSR1, &act1, NULL) != 0)
	{
		printf("sigaction Error\n");
		exit(1);
	}
	if(sigaction(SIGUSR2, &act1, NULL) != 0)
	{
		printf("sigaction error");
		exit(1);
	}
	while(1)
		;
	return (0);
}
