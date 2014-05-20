/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 06:01:13 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/18 06:01:57 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct	s_builtin
{
	char		*name;
	int			(*fun)(int, char *);
}				t_builtin;

typedef struct	s_cmdclient
{
	char		cmd[8];
}				t_cmdclient;

#endif
