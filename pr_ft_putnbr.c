#include "ft_printf.h"

int	pr_put_unsigned(unsigned int n)
{
    int count;

	count = 0;
	if (n >= 10)
		count += pr_put_unsigned(n / 10);
	count += pr_ft_char((n % 10) + '0');
    
    return(count);
}

int	pr_ft_putnbr(int n)
{
    int count;

	count = 0;
	if (n >= 0)
		count += pr_put_unsigned((unsigned int)n);
	if (n < 0)
	{
		count += pr_ft_char('-') + pr_put_unsigned((unsigned int)-n);
	}

    return(count);
}