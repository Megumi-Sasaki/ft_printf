#include "ft_printf.h"

int pr_ft_0x(void)
{
    int count;

    count = 0;
    count += pr_ft_putstr("0x");

    return (count);
}


int pr_ft_putpointer(uintptr_t ptr) 
{
    int count;

    count = 0;
    if (ptr == 0)
        count += pr_ft_char('0');
    else {
        if (ptr >= 16)
            count += pr_ft_putpointer(ptr / 16);
        count += pr_ft_char("0123456789abcdef"[ptr % 16]);
    }

    return count;
}