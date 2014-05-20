/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:25:07 by jyim              #+#    #+#             */
/*   Updated: 2014/03/23 01:37:42 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cnt;
	int		cnt2;
	int		cnttempo;
	char	*new;

	cnt = ft_strlen(s1);
	cnt2 = 0;
	cnttempo = ft_strlen(s2);
	new = (char*)malloc(sizeof(char*) * (cnt + cnttempo + 1));
	if (new == NULL)
		return (NULL);
	while (s1[cnt2] != '\0')
	{
		new[cnt2] = s1[cnt2];
		cnt2++;
	}
	cnt = 0;
	while (s2[cnt] != '\0')
	{
		new[cnt2] = s2[cnt];
		cnt2++;
		cnt++;
	}
	new[cnt2] = '\0';
	return (new);
}
