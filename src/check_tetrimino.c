/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:09:26 by yhliboch          #+#    #+#             */
/*   Updated: 2018/12/22 17:23:15 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_tetrim(char *str)
{
	static int		letter = 65;
	static t_list	*list;
	t_list			*temp;
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = letter;
		i++;
	}
	if (list == NULL)
		list = ft_lstnew(str, letter);
	else
	{
		temp = list;
		while (temp)
			temp = temp->next;
		ft_lstadd(&list, ft_lstnew(str, letter));
	}
	letter++;
}

int		check_relations(char *str, int side)
{
	int		i;
	int		cons;

	cons = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				cons++;
			if (str[i - 1] == '#')
				cons++;
			if (i + side + 1 < side * side + side)
				if (str[i + side + 1] == '#')
					cons++;
			if (i - (side + 1) >= 0)
				if (str[i - (side + 1)] == '#')
					cons++;
		}
		i++;
	}
	if (cons != 6 && cons != 8)
		return (0);
	return (1);
}

int		check_symb(char *str, int side)
{
	int i;
	int h;
	int n;

	i = 0;
	h = 0;
	n = 0;
	if ((str[0] != '.' && str[0] != '#') || str[side - 1] == '\n')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		if (str[i] == '#')
			h++;
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		i++;
	}
	if (h != 4 || n < side)
		return (0);
	return (1);
}

t_list	*check_tetrim(char *str, int side)
{
	static t_list	*list;
	t_list			*temp;
	char			*tmp;

	if (check_symb(str, side) == 1 && check_relations(str, side) == 1)
	{
		if (list == NULL)
		{
			tmp = toleft(str);
			list = ft_lstnew(tmp, 21);
			free(tmp);
		}
		else
		{
			temp = list;
			while (temp->next != NULL)
				temp = temp->next;
			tmp = toleft(str);
			ft_lstaddend(&temp, ft_lstnew(tmp, 21));
			free(tmp);
		}
		return (list);
	}
	return (NULL);
}
