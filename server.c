/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 07:59:54 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/18 07:59:55 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int				server_init(char *port)
{
	int							s;
	struct sockaddr_in			addr;

	if ((s = socket(PF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto)) <= 0)
		return (-1);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(ft_atoi(port));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(s, (const struct sockaddr *)&addr, sizeof(addr)))
		return (-1);
	if (listen(s, 13))
		return (-1);
	return (s);
}

t_builtin		*get_instance(void)
{
	static t_builtin	*built = NULL;

	if (!built)
	{
		built = (t_builtin*)malloc(sizeof(t_builtin) * 6);
		built[0].name = ft_strdup("ls");
		built[0].fun = client_ls;
		built[1].name = ft_strdup("cd");
		built[1].fun = client_cd;
		built[2].name = ft_strdup("get");
		built[2].fun = client_get;
		built[3].name = ft_strdup("put");
		built[3].fun = client_put;
		built[4].name = ft_strdup("pwd");
		built[4].fun = client_pwd;
		built[5].name = NULL;
		built[5].fun = NULL;
	}
	return (built);
}

int				server(int sock)
{
	char					buf[1024];
	int						ret;
	int						i;
	t_builtin				*tab;

	tab = get_instance();
	while ((ret = recv(sock, buf, 1024, 0)) > 0)
	{
		i = 0;
		buf[ret - 1] = '\0';
		while (tab[i].name &&
				ft_strncmp(tab[i].name, buf, ft_strlen(tab[i].name)))
			i++;
		if (tab[i].fun)
		{
			if (tab[i].fun(sock, buf + ft_strlen(tab[i].name) + 1) == -1)
				send(sock, "ERROR\n", 6, 0);
		}
		else
			send(sock, "Unknow command\n", 15, 0);
		send(sock, STR_EOR, 2, 0);
		ft_bzero(buf, 1024);
	}
	return (0);
}

int				usage(char *name)
{
	printf("Usage: %s <port>\n", name);
	return (-1);
}

int				main(int ac, char **av)
{
	int						socks[2];
	struct sockaddr_in		csockaddr;
	unsigned int			csockln;
	pid_t					child;

	if (ac != 2)
		return (usage(av[0]));
	if (!(getcwd(g_path, MAXPATHLEN)))
		return (-1);
	if ((socks[0] = server_init(av[1])) < 0)
		return (-1);
	while ((socks[1] = accept(socks[0],
					(struct sockaddr *)&csockaddr, &csockln)) > 0)
	{
		if ((child = fork()) == -1)
			return (-1);
		if (!child)
		{
			server(socks[1]);
			return (0);
		}
	}
	return (0);
}
