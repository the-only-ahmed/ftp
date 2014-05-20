/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_rev_list_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:21:32 by jyim              #+#    #+#             */
/*   Updated: 2013/12/07 16:30:44 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	aff_rev_list_str(t_list *new)
{
	if (new == NULL)
		return ;
	else
		aff_rev_list_str(new->next);
	ft_putendl(new->content);
}
