/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:27:40 by jyim              #+#    #+#             */
/*   Updated: 2014/03/27 19:11:27 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					verif_token_m(char c, int q, char *qt)
{
	if (c == '"' || c == '\'' || c == '`')
	{
		if (!q)
			*qt = c;
		if (*qt == c)
			q = (q) ? 0 : 1;
	}
	return (q);
}

int					is_t(int c)
{
	if (c == ';')
		return (1);
	return (0);
}

static int			ft_count_split(char const *s)
{
	int		i;
	int		i2;
	int		i3;

	i = 0;
	i2 = 0;
	i3 = 0;
	while (s[i2] != '\0')
	{
		if (is_t(s[i2]))
		{
			i3++;
			i2++;
		}
		if (!is_t(s[i2]))
		{
			i2++;
			i++;
		}
	}
	return (i + i3);
}

static char			*fill_mult(t_mult *m, char *s, int bol)
{
	if (bol == 0)
	{
		m->i = 0;
		m->p = 0;
		m->q = 0;
		m->qt = 0;
		m->i2 = 0;
		m->cnt = 0;
		if (s == NULL)
			return (NULL);
		m->tmp = (char**)malloc(sizeof(char*) * (ft_count_split(s) + 1));
	}
	else
	{
		m->cnt++;
		if (((m->i && s[m->i - 1] != '\\') || (m->i == 0)) && s[m->i] == '(')
			m->p++;
		if (((m->i && s[m->i - 1] != '\\') || (m->i == 0)) && s[m->i] == ')')
			m->p--;
	}
	return (s);
}

char				**ft_strsplit_mult(char const *s)
{
	t_mult		m;

	if (fill_mult(&m, (char *)s, 0) == NULL)
		return (NULL);
	while (s[m.i] != '\0')
	{
		if (((m.i && s[m.i - 1] != '\\') || (m.i == 0)) && s[m.i] == '(')
			m.p++;
		if (((m.i && s[m.i - 1] != '\\') || (m.i == 0)) && s[m.i] == ')')
			m.p--;
		while (mult_1(s, m))
		{
			m.tmp[m.i2] = ft_strsub(s, m.i, 1);
			m.i2++;
			m.i++;
		}
		while (mult_2(s, m))
			fill_mult(&m, (char *)s, 1);
		m.tmp[m.i2] = ft_strsub(s, m.i, m.cnt);
		m.i = m.cnt + m.i;
		m.i2++;
	}
	m.tmp[m.i2] = NULL;
	return (m.tmp);
}
