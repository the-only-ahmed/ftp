/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:34:08 by jyim              #+#    #+#             */
/*   Updated: 2014/01/12 01:49:45 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_resostr(const char *s1, const char *s2)
{
	int			i;
	int			cnt;
	char		*tmp;

	i = 0;
	cnt = 0;
	while (s1[i] != 0)
	{
		while (s1[i] == s2[cnt])
		{
			i++;
			cnt++;
			if (s2[cnt] == 0)
			{
				tmp = (char *)&s1[i - cnt];
				return (tmp);
			}
		}
		cnt = 0;
		i++;
	}
	return (NULL);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	char	*tmp;

	if (*s2 == '\0')
		tmp = (char *)s1;
	else
		tmp = ft_resostr(s1, s2);
	return (tmp);
}
