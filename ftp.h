/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 08:00:19 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/18 08:00:21 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# include <sys/param.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <netdb.h>
# include <dirent.h>
# include <fcntl.h>
# include <stdio.h>
# include <libft.h>
# include "list.h"

# define STR_EOR "\xFF\x1"
# define STR_CLEAR "\x1b[2J\x1b[H"

char		g_path[MAXPATHLEN];

int		client(int sock);
int		get_file(char *buf);
int		put_file(char *arg, int sock);

int		client_ls(int s, char *a);
int		client_pwd(int s, char *a);
int		client_cd(int s, char *a);
int		client_get(int s, char *a);
int		client_put(int s, char *a);

#endif
