#include "ft_printf.h"

int pr_ft_putstr(const char *s)
{
    if(!s)
    {
        write(1, "NULL", 4);
        return (4);
    }
    ft_putstr_fd(s);
    return ((int)ft_strlen(s));
}