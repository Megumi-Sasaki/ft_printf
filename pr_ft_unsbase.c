#include "ft_printf.h"

int	pr_ft_puthex(unsigned int n, int uppercase)
{
	int count;
    count = 0;
	if (n >= 16)
		count += pr_ft_puthex(n / 16, uppercase);
	if (uppercase)
		count += pr_ft_char("0123456789ABCDEF"[n % 16]);
	else
		count += pr_ft_char("0123456789abcdef"[n % 16]);

	return(count);
}

int pr_ft_unsbase(unsigned int n, const char *base_str)//uxX
{
	int count;

	count = 0;
	if(*base_str == 'u')
		count += pr_put_unsigned(n);
	else if(*base_str == 'x')
		count += pr_ft_puthex(n, 0);
	else if(*base_str == 'X')
		count += pr_ft_puthex(n, 1);
	
	return (count);
}