/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_list_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 21:51:13 by jyim              #+#    #+#             */
/*   Updated: 2013/12/07 16:30:29 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	aff_list_str(t_list *new)
{
	if (new == NULL)
		return ;
	else
	{
		ft_putendl(new->content);
		aff_list_str(new->next);
	}
}
