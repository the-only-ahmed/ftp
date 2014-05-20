/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_mult_def.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:10:28 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 12:39:24 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		mult_1(char const *s, t_mult m)
{
	return (s[m.i] != '\0' && !m.p &&
	((m.i && s[m.i - 1] != '\\') || !m.i) && is_t(s[m.i]) &&
	!verif_token_m(s[m.i], m.q, &(m.qt)));
}

int		mult_2(char const *s, t_mult m)
{
	return (s[m.i + m.cnt] &&
	(m.p || verif_token_m(s[m.i + m.cnt], m.q, &(m.qt)) ||
	!is_t(s[m.i + m.cnt]) || (s[m.i + m.cnt - 1] &&
	s[m.i + m.cnt - 1] == '\\' && !is_t(s[m.i + m.cnt]))));
}
