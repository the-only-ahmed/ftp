/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_norme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 06:32:09 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/18 07:33:47 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	tech(char **buf, int sock, int ret, int fd)
{
	if (fd == -1)
	{
		printf("ERROR\n");
		return ;
	}
	send(sock, *buf, ret, 0);
	ft_bzero(*buf, 1024);
	while ((ret = recv(sock, *buf, 1024, 0)))
	{
		if (!ft_strncmp(*buf + ret - 2, STR_EOR, 2))
		{
			write(fd, *buf, ret - 2);
			break ;
		}
		write(fd, *buf, ret);
		ft_bzero(*buf, 1024);
	}
}

char	*norme(int *fd, int *ret, char *buf)
{
	static int		i;

	if (!i)
	{
		buf = (char*)malloc(sizeof(char) * 1025);
		i++;
	}
	*fd = 1;
	ft_bzero(buf, 1024);
	*ret = read(1, buf, 1024);
	buf[*ret - 1] = '\0';
	return (buf);
}

int		client(int sock)
{
	int			fd;
	int			ret;
	char		*buf;

	while (ft_putstr("$> "), 1)
	{
		buf = norme(&fd, &ret, buf);
		if (!ft_strncmp("get", buf, 3))
			fd = get_file(buf + 4);
		else if (!ft_strncmp("put", buf, 3))
		{
			send(sock, buf, ret, 0);
			put_file(buf + 4, sock);
			continue ;
		}
		else if (!ft_strncmp("quit", buf, 4))
			break ;
		else if (!ft_strncmp("clear", buf, ft_strlen("clear")))
		{
			ft_putstr(STR_CLEAR);
			continue ;
		}
		tech(&buf, sock, ret, fd);
	}
	return (0);
}
