/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:17:41 by yhliboch          #+#    #+#             */
/*   Updated: 2018/12/22 17:24:10 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(int fd)
{
	char	*buf;
	t_list	*list;
	int		ret;
	int		sum;
	int		num;

	buf = ft_strnew(21);
	sum = 0;
	num = 0;
	g_side = 0;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		sum += ret;
		if ((list = check_tetrim(buf, 4)) == NULL)
			return (0);
		num++;
	}
	if ((sum + 1) % 21 != 0 || num > 26)
		return (0);
	options(&list, num, square_size(num));
	free(buf);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) > 0)
		if (ft_read(fd) == 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
	close(fd);
	return (0);
}
