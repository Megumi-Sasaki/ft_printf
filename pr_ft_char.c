
#include "ft_printf.h"

int pr_ft_char(char c)
{
    return write(1, &c, 1);
}