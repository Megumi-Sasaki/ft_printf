/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:31:26 by mesasaki          #+#    #+#             */
/*   Updated: 2024/12/17 15:37:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	support_printf(const char *format, va_list args, size_t count)
{
	if (*format == 'c')
		count += pr_putchar(va_arg(args, int), count);
	else if (*format == 'd' || *format == 'i')
		count += pr_putnbr(va_arg(args, int));
	else if (*format == 's')
		count += pr_putstr(va_arg(args, char *), count);
	else if (*format == 'u' || *format == 'X' || *format == 'x')
		count += pr_unsbase(va_arg(args, unsigned int), *format);
	else if (*format == 'p')
	{
		count += pr_putpointer(va_arg(args, uintptr_t));
	}
	else
	{
		count += pr_putchar('%');
		count += pr_putchar(*format, count);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += support_printf(format, args, count);
		}
		else
		{
			count += pr_putchar(*format, count);
		}
		format++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int i;
// 	int original;
// 	int *point;
// 	int test;

// 	test = 3;
// 	point = &test;

// 	i = ft_printf("%c\n", 'A');
// 	original = printf("%c\n", 'A');
// 	printf("%i\n", i);
// 	printf("%i\n", original);

// 	i = ft_printf("%d\n", -12345);
// 	original = printf("%d\n", -12345);
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = ft_printf("%s\n", "ABCDE");
// 	original = printf("%s\n", "ABCDE");
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = ft_printf("%u\n", 456);
// 	original = printf("%u\n", 456);
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = ft_printf("debug:%u\n", -456);
// 	original = printf("debug:%u\n", -456);
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = ft_printf("%x\n", 255);
// 	original = printf("%x\n", 255);
// 	printf("%x\n", i);
// 	printf("%x\n", original);

// 	i = ft_printf("%x\n", -123);
// 	original = printf("%x\n", -123);
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = ft_printf("%X\n", -123);
// 	original = printf("%X\n", -123);
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = printf("%p\n", &point);
// 	original = ft_printf("%p\n", &point);
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = printf("%%aaaaa\n");
// 	original = ft_printf("%%aaaaa\n");
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = printf("%% %%\n");
// 	original = ft_printf("%% %%\n");
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	i = printf("NULL %s NULL \n", "");
// 	original = ft_printf("NULL %s NULL \n", "");
// 	printf("%d\n", i);
// 	printf("%d\n", original);

// 	ft_printf("Hello %s! This is a number: %d and a char: %c\n", "World", 42,
// 		'A');

// 	i = printf("debug:%p\n", NULL);
// 	original = ft_printf("debug:%p\n", NULL);
// 	printf("%d\n", i);
// 	printf("%d\n", original);
// 	return (0);
// }