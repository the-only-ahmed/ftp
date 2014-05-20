/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 01:37:19 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/03/27 12:09:14 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinjoin(char const *s1, char const *s2, int pos)
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
	while (cnt2 < pos)
	{
		new[cnt2] = s1[cnt2];
		cnt2++;
	}
	new = ft_strjoin(new, s2);
	new = ft_strjoin(new, &s1[pos]);
	return (new);
}
