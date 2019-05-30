/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:06:51 by yhliboch          #+#    #+#             */
/*   Updated: 2018/12/22 14:06:53 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*create_elem(int x, int y)
{
	t_matrix	*elem;

	if ((elem = (t_matrix *)malloc(sizeof(t_matrix) * 1)) != NULL)
	{
		elem->x = x;
		elem->y = y;
		elem->down = NULL;
		return (elem);
	}
	return (NULL);
}

void		elem_del(t_matrix **elem)
{
	t_matrix	*elem1;

	elem1 = *elem;
	elem1->right = NULL;
	elem1->left = NULL;
	elem1->down = NULL;
	elem1->up = NULL;
	elem1->head = NULL;
	free(elem1);
}

void		matrix_del(t_matrix **start)
{
	t_matrix	*temp;
	t_matrix	*tmp;
	t_matrix	*cl;
	t_matrix	*col;
	t_matrix	*start1;

	start1 = *start;
	col = start1->right;
	while (start1->right != start1)
	{
		temp = col->down;
		col->right->left = col->left;
		col->left->right = col->right;
		while (temp->down != temp)
		{
			temp->up->down = temp->down;
			temp->down->up = temp->up;
			tmp = temp;
			temp = temp->down;
			elem_del(&tmp);
		}
		cl = col;
		col = col->right;
		elem_del(&cl);
	}
}

t_matrix	*make_start(t_matrix **start, t_list **list, int side, int num)
{
	t_list	*temp;

	temp = (*list);
	if (*start == NULL)
	{
		*start = create_elem(-1, -1);
		*start = make_hed(start, num, side * side);
	}
	while (temp != NULL)
	{
		*start = combinations(start, temp->content, side);
		temp = temp->next;
	}
	last_row(*start);
	return (*start);
}
