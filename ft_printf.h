# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
#include <stdio.h>


int ft_printf(const char *format, ...);
int support_printf(const char *format, va_list args);
int pr_ft_char(char c);
int	pr_ft_putnbr(int n);
int pr_ft_putstr(const char *s);
int pr_ft_unsbase(unsigned int n, const char *base_str);
int	pr_put_unsigned(unsigned int n);
int	pr_ft_puthex(unsigned int n, int uppercase);
int pr_ft_putpointer(uintptr_t ptr);
int pr_ft_0x(void);
void	ft_putstr_fd(const char *s);
size_t	ft_strlen(const char *str);

#endif