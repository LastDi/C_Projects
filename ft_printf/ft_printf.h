/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:01:07 by oalvera           #+#    #+#             */
/*   Updated: 2021/12/04 20:01:36 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putnbr(int i);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_match(char c, va_list ap);
int	ft_uns_putnbr(unsigned int i);
int	ft_printf(const char *s, ...);
int	ft_putpointer(void *p, char *s);
int	ft_puthex(unsigned int i, char *s);

#endif
