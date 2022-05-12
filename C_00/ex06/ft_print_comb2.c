#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	out(int x, int y)
{	
		ft_putchar(x / 10 + '0');
		ft_putchar(x % 10 + '0');
		ft_putchar(' ');
		ft_putchar(y / 10 + '0');
		ft_putchar(y % 10 + '0');
		if(x != 98 ||  y != 99)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			out(a, b);
			b++;
		}
		a++;
	}
}	

int	main(void)
{
	ft_print_comb2();
	return (0);
}
