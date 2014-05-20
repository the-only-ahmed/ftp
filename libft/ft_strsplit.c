/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:27:40 by jyim              #+#    #+#             */
/*   Updated: 2014/01/12 01:49:38 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_split(char const *s, char c)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (s[i2] != '\0')
	{
		if (s[i2] == c)
			i2++;
		if (s[i2] != c)
		{
			i2++;
			i++;
		}
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tmp;
	int			i;
	int			i2;
	size_t		cnt;

	i = 0;
	i2 = 0;
	if (s == NULL)
		return (NULL);
	tmp = (char**)malloc(sizeof(char*) * (ft_count_split(s, c) + 1));
	while (s[i] != '\0')
	{
		cnt = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + cnt] != c && s[i + cnt] != '\0')
			cnt++;
		tmp[i2] = ft_strsub(s, i, cnt);
		i = cnt + i;
		i2++;
	}
	tmp[i2] = NULL;
	return (tmp);
}
