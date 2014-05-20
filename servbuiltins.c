/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servbuiltins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 08:00:07 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/05/18 08:30:24 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int		client_pwd(int s, char *arg)
{
	char	*pwd;
	char	*xxx;

	(void)arg;
	pwd = NULL;
	if (!(pwd = getcwd(pwd, MAXPATHLEN)))
		return (-1);
	pwd = ft_strjoin(pwd, "/\n");
	if (!(xxx = ft_strstr(pwd, g_path)))
		return (-1);
	xxx += ft_strlen(g_path);
	free(pwd);
	send(s, xxx, ft_strlen(xxx), 0);
	return (0);
}

int		client_get(int s, char *arg)
{
	int				fd;
	int				ret;
	char			buf[1024];

	if ((fd = open(arg, O_RDONLY)) < 0)
		return (-1);
	while ((ret = read(fd, buf, 1024)))
	{
		send(s, buf, ret, 0);
		ft_bzero(buf, 1024);
	}
	return (0);
}

int		client_put(int s, char *arg)
{
	int		fd;
	int		ret;
	char	buf[1024];

	if ((fd = open(arg, O_RDONLY)) >= 0)
	{
		close(fd);
		fd = open("/dev/null", O_RDWR, 0666);
	}
	if ((fd = open(arg, O_CREAT | O_RDWR, 0666)) < 0)
		return (-1);
	ft_bzero(buf, 1024);
	while ((ret = recv(s, buf, 1024, 0)))
	{
		write(fd, buf, ret);
		ft_bzero(buf, 1024);
		if (!(ft_strncmp(buf + ret - 2, STR_EOR, 2)))
			break ;
	}
	close(fd);
	return (0);
}

int		client_cd(int s, char *arg)
{
	char		prevpath[MAXPATHLEN];
	char		path[MAXPATHLEN];

	(void)s;
	if (!(getcwd(prevpath, MAXPATHLEN)))
		return (-1);
	if ((chdir(arg)))
		return (-1);
	if (!(getcwd(path, MAXPATHLEN)))
	{
		chdir(prevpath);
		return (-1);
	}
	if (ft_strncmp(path, g_path, ft_strlen(g_path)))
	{
		chdir(prevpath);
		return (-1);
	}
	return (0);
}

int		client_ls(int s, char *arg)
{
	DIR				*dir;
	struct dirent	*file;

	(void)arg;
	dir = opendir(".");
	while ((file = readdir(dir)))
	{
		if (file->d_name[0] != '.')
		{
			send(s, file->d_name, ft_strlen(file->d_name), 0);
			send(s, "\n", 1, 0);
		}
	}
	return (0);
}
