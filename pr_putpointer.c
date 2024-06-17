/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:31:59 by mesasaki          #+#    #+#             */
/*   Updated: 2024/06/18 04:01:39 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pr_0x(void)
{
	int	count;

	count = 0;
	count += pr_putstr("0x");
	return (count);
}

int	pr_putpointer(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += pr_putchar('0');
	else
	{
		if (ptr >= 16)
			count += pr_putpointer(ptr / 16);
		count += pr_putchar("0123456789abcdef"[ptr % 16]);
	}
	return (count);
}
