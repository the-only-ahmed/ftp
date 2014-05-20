/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_defines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:45:49 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 13:25:05 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		sym_int(char const *str, int i)
{
	return (str[i + 1] == '#' || str[i + 1] == '-' ||
	(str[i + 1] == '.' && (str[i + 2] == 'd' || str[i + 2] == 'i')));
}

int		symb_int(char const *str, int *i)
{
	return (str[*i + 1] == 'd' || str[*i + 1] == 'i' ||
	((str[*i + 1] == ' ' || str[*i + 1] == '+') &&
	(str[*i + 2] == 'd' || str[*i + 2] == 'i')));
}

int		sym_char(char const *str, int *i)
{
	return (str[*i + 1] == 'c' || ((str[*i + 1] == ' ' ||
	str[*i + 1] == '+' || str[*i + 1] == '.') && str[*i + 2] == 'c'));
}
