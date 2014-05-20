/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 07:59:44 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/18 07:59:46 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int		client_init(char *port, char *in)
{
	int							s;
	struct sockaddr_in			addr;

	if ((s = socket(PF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto)) <= 0)
		return (-1);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(ft_atoi(port));
	addr.sin_addr.s_addr = inet_addr(in);
	if (connect(s, (const struct sockaddr *)&addr, sizeof(addr)))
		return (-1);
	return (s);
}

int		get_file(char *buf)
{
	int		fd;

	if ((fd = open(buf, O_CREAT | O_RDWR, 0666)) < 0)
	{
		printf("ERROR\n");
		return (-1);
	}
	return (fd);
}

int		put_file(char *arg, int sock)
{
	int		fd;
	char	buf[1024];
	int		ret;

	if ((fd = open(arg, O_RDONLY)) < 0)
	{
		printf("ERROR\n");
		return (-1);
	}
	while ((ret = read(fd, buf, 1024)))
	{
		send(sock, buf, ret, 0);
		ft_bzero(buf, ret);
	}
	send(sock, STR_EOR, 2, 0);
	return (0);
}

int		usage(char *name)
{
	printf("Usage: %s <addr> <port>\n", name);
	return (-1);
}

int		main(int ac, char **av)
{
	int		sock;

	if (ac != 3)
		return (usage(av[0]));
	if ((sock = client_init(av[2], av[1])) < 0)
	{
		printf("ERROR\n");
		return (-1);
	}
	client(sock);
	close(sock);
	return (0);
}
