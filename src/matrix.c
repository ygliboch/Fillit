/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:51:20 by yhliboch          #+#    #+#             */
/*   Updated: 2018/12/22 17:24:21 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			last_row(t_matrix *start)
{
	t_matrix	*column;
	t_matrix	*row;

	row = start->right;
	while (row != start)
	{
		column = row;
		while (column->down)
			column = column->down;
		column->down = row;
		row->up = column;
		row = row->right;
	}
}

void			make_row2(t_matrix *start, t_matrix *work, int y, int *cor)
{
	t_matrix	*newelem;
	t_matrix	*column;
	t_matrix	*temp;
	int			i;

	i = 0;
	temp = start;
	while (i < 4)
	{
		while (work->x != cor[i])
			work = work->right;
		column = work;
		while (column->down)
			column = column->down;
		newelem = create_elem(cor[i], y);
		start->right = newelem;
		newelem->left = start;
		newelem->up = column;
		column->down = newelem;
		newelem->head = work;
		newelem->right = temp;
		temp->left = newelem;
		start = newelem;
		i++;
	}
}

void			make_row(t_matrix *work, int *cor, int letter)
{
	t_matrix		*newelem;
	t_matrix		*start;
	t_matrix		*temp;

	while (work->x != -letter + 64)
		work = work->right;
	temp = work;
	while (temp->down)
	{
		temp = temp->down;
	}
	newelem = create_elem(-1, g_y);
	temp->down = newelem;
	newelem->up = temp;
	newelem->head = work;
	start = newelem;
	make_row2(start, work, g_y, cor);
	free(cor);
	g_y++;
}

void			make_hed2(int s, t_matrix **elem, t_matrix **temp)
{
	int	i;

	i = 0;
	while (i < s)
	{
		*elem = create_elem(i, -1);
		(*elem)->head = *elem;
		(*elem)->left = *temp;
		(*temp)->right = *elem;
		*temp = *elem;
		i++;
	}
}

t_matrix		*make_hed(t_matrix **start, int num, int s)
{
	t_matrix	*elem;
	t_matrix	*temp;
	int			i;
	t_matrix	*start1;

	i = 0;
	temp = *start;
	start1 = *start;
	while (i < num)
	{
		elem = create_elem(-i - 1, -1);
		elem->head = elem;
		elem->left = temp;
		temp->right = elem;
		temp = elem;
		i++;
	}
	make_hed2(s, &elem, &temp);
	temp->right = *start;
	start1->left = temp;
	start1->head = start1;
	return (*start);
}
