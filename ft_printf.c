#include "ft_printf.h"
#include <stdio.h>

int support_printf(const char *format, va_list args)
{
        int count;

        count = 0;
    if (*format == 'c') 
        count += pr_ft_char(va_arg(args, int));
    else if (*format == 'd' || *format == 'i') 
        count += pr_ft_putnbr(va_arg(args, int));
    else if (*format == 's')
        count += pr_ft_putstr(va_arg(args, char *));
    else if (*format == 'u' || *format == 'X' || *format == 'x') 
        count += pr_ft_unsbase(va_arg(args, unsigned int), format);
    else if (*format == 'p') 
        {
            count += pr_ft_0x();
            count += pr_ft_putpointer(va_arg(args, uintptr_t));
        }
    else
    {
        count += pr_ft_char(*format);
    }

    return count;
}

int ft_printf(const char *format, ...) 
{
    va_list args;
    va_start(args, format);
    size_t count;

    count = 0;
     while (*format) {
        if (*format == '%') {
            format++;
            count += support_printf(format, args);
        } else {
            count += pr_ft_char(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() 
{   
    int i;
    int original;
    int *point;
    int test;

    test = 3;
    point = &test;

    i = ft_printf("%c\n", 'A');
    original = printf("%c\n", 'A');
    printf("%i\n", i);
    printf("%i\n", original);

    i = ft_printf("%d\n", -12345);
    original = printf("%d\n", -12345);
    printf("%d\n", i);
    printf("%d\n", original);

    i = ft_printf("%s\n", "ABCDE");
    original = printf("%s\n", "ABCDE");
    printf("%d\n", i);
    printf("%d\n", original);

    i = ft_printf("%u\n", 456);
    original = printf("%u\n", 456);
    printf("%d\n", i);
    printf("%d\n", original);

    i = ft_printf("%x\n", 255);
    original = printf("%x\n", 255);
    printf("%x\n", i);
    printf("%x\n", original);

    i = printf("%p\n", &point);
    original = ft_printf("%p\n", &point);
    printf("%d\n", i);
    printf("%d\n", original);

    i = printf("%%aaaaa\n");
    original = ft_printf("%%aaaaa\n");
    printf("%d\n", i);
    printf("%d\n", original);

    i = printf("%% %%\n");
    original = ft_printf("%% %%\n");
    printf("%d\n", i);
    printf("%d\n", original);

    i = printf("NULL %s NULL \n", "");
    original = ft_printf("%% %%\n");
    printf("%d\n", i);
    printf("%d\n", original);

    i = printf("NULL %s NULL \n", NULL); //　←　エラーが起きる部分
    original = ft_printf("%% %%\n");
    printf("%d\n", i);
    printf("%d\n", original);

    ft_printf("Hello %s! This is a number: %d and a char: %c\n", "World", 42, 'A');
    return 0;
}