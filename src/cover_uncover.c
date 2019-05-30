/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_uncover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:33:59 by omaltsev          #+#    #+#             */
/*   Updated: 2018/12/22 17:23:49 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_stack		*stacknew(t_matrix *row)
{
	t_stack	*new;

	if ((new = (t_stack *)malloc(sizeof(t_stack) * 1)) != NULL)
	{
		new->matrix = row;
		new->next = NULL;
	}
	return (new);
}

void		uncover_row(t_matrix *row)
{
	t_matrix	*temp;
	t_matrix	*tmp;
	t_matrix	*head;

	temp = row->down;
	head = row->head;
	head->left->right = head;
	head->right->left = head;
	while (temp->y != -1)
	{
		temp->up->down = temp;
		temp->down->up = temp;
		tmp = temp->right;
		while (tmp != temp)
		{
			tmp->up->down = tmp;
			tmp->down->up = tmp;
			tmp = tmp->right;
		}
		temp = temp->down;
	}
}

void		uncover(t_stack **stack)
{
	t_matrix	*temp;
	t_matrix	*row;
	t_stack		*tmp;

	row = (*stack)->matrix;
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	temp = row;
	while (row->right != temp)
	{
		row->up->down = row;
		row->down->up = row;
		uncover_row(row);
		row = row->right;
	}
	row->up->down = row;
	row->down->up = row;
	uncover_row(row);
}

void		cover_row(t_matrix *row)
{
	t_matrix	*temp;
	t_matrix	*tmp;
	t_matrix	*head;

	head = row->head;
	head->left->right = head->right;
	head->right->left = head->left;
	temp = row->down;
	while (temp->y != -1)
	{
		tmp = temp->right;
		while (tmp != temp)
		{
			tmp->up->down = tmp->down;
			tmp->down->up = tmp->up;
			tmp = tmp->right;
		}
		temp->up->down = temp->down;
		temp->down->up = temp->up;
		temp = temp->down;
	}
}

void		cover(t_matrix *row, t_stack **stack, t_matrix **start)
{
	t_matrix	*temp;
	t_stack		*new;

	if (*stack == NULL)
		*stack = stacknew(row);
	else
	{
		new = stacknew(row);
		new->next = *stack;
		*stack = new;
	}
	temp = row;
	while (row->right != temp)
	{
		if (row == *start)
			return ;
		row->up->down = row->down;
		row->down->up = row->up;
		cover_row(row);
		row = row->right;
	}
	row->up->down = row->down;
	row->down->up = row->up;
	cover_row(row);
}
