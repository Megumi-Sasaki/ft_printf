/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:32:49 by mesasaki          #+#    #+#             */
/*   Updated: 2024/06/17 21:36:39 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		support_printf(const char *format, va_list args);
int		pr_ft_char(char c);
int		pr_ft_putnbr(int n);
int		pr_ft_putstr(const char *s);
int		pr_ft_unsbase(unsigned int n, const char *base_str);
int		pr_put_unsigned(unsigned int n);
int		pr_ft_puthex(unsigned int n, int uppercase);
int		pr_ft_putpointer(uintptr_t ptr);
int		pr_ft_0x(void);
int		ft_putstr_fd(const char *s);
size_t	ft_strlen(const char *str);

#endif