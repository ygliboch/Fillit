/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dancing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:18:20 by yhliboch          #+#    #+#             */
/*   Updated: 2018/12/22 17:24:53 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			work(t_matrix **start, t_stack **stack)
{
	t_matrix	*row;

	row = (*start)->right->down;
	if ((*start)->right->x >= 0 || (*start)->right == *start)
		return (1);
	while (row != (*start)->right && row->y != -1)
	{
		cover(row, stack, start);
		if (work(start, stack))
			return (1);
		else
		{
			uncover(stack);
			row = row->down;
		}
	}
	return (0);
}

void		options(t_list **list, int num, int side)
{
	static t_stack		*stack;
	static t_matrix		*start;

	start = make_start(&start, list, side, num);
	if (work(&start, &stack) == 1)
		make_square(stack, side, num);
	else
	{
		g_y = 0;
		side++;
		matrix_del(&start);
		del_stack(&stack);
		free(start);
		start = NULL;
		options(list, num, side);
	}
}
