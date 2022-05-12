#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<setjmp.h>

void	sig_int(int singno)
{
	volatile int k = 0;
	int i, j;
	printf("sig_int starg\n");

	for(i = 0; i < 300; i++)
	{
		for(j = 0; j < 6000000; j++)
			k+=i * j;
	}
	printf("sig_int end\n");
}

void	sig_quit(int signo)
{
	volatile int k = 0;
	int i , j;
	printf("sig_quit start\n");
	for(i = 0; i < 300; i++)
	{
		for(j = 0; j < 6000000; j++)
			k += i * j;
	}
	printf("sig_quit end\n");
}

int main()
{
	signal(SIGINT, sig_int);
	signal(SIGQUIT, sig_quit);
	pause(); // 신호 발생 되고 처리될 때 까지 대기 
	printf("process end\n");
}

