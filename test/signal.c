#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void (*old_fun)(int);

void	sigint_handler(int signo)
{
	printf("CrtlC를 눌렀네\n");
	printf("또누르면 끝난다~~\n");
	signal(SIGINT, old_fun);
}

int main(void)
{
	old_fun = signal(SIGINT, sigint_handler);
	while(1)
	{
		printf("아아\n");
		sleep(1);
	}
}
