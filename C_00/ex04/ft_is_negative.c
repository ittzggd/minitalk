#include<unistd.h>

char	ft_char(char c)
{
	write (1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0 )
		ft_char('N');
	else
		ft_char('P');
}

int	main(void)
{
	ft_is_nagative();
	ft_is_negative();
}
