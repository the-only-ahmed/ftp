/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 16:41:40 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/04/27 22:53:48 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
int		ft_putstr(char const *str);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *str);
int		ft_point(char const *str, int *i, int x, char *c);
int		ft_putunsigned_int(unsigned int n, int base);
int		ft_putunsigned_long(void *p, int base);
int		ft_putunsigned_2long(unsigned long long n);
int		condition(const char *str, int *i, va_list ap);
int		ft_abs(int x);
int		ft_all(const char *str, int *i, va_list ap);
int		ft_isascii(int c);
int		ft_all_2(int *i, const char *str, int x, int next);
int		first_else(int x, int next, char str, char c);
int		second_else(int x, int next, char str, char c);

int		ft_cond_2(const char *str, int *i, va_list ap);
int		ft_cond_1(const char *str, int *i, va_list ap, int x);
int		ft_cond_1c(int length, const char *str, int *i, va_list ap);
int		ft_cond_3(const char *str, int *i, int x);
int		ft_cond_3c(const char *str, int *i, int x);
int		condition_2(const char *str, int *i, va_list ap);
int		condition_3(const char *str, int *i, va_list ap);
int		condition_4(const char *str, int *i, va_list ap);
int		condition_5(const char *str, int *i, va_list ap, int length);

char	*ft_itoa_float(double x);
double	ft_atoi_float(const char *str);

int		sym_int(char const *str, int i);
int		symb_int(char const *str, int *i);
int		sym_char(char const *str, int *i);

int		ft_printpointeur(void *p);
char	*printpointeur(void *p, unsigned long div);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
