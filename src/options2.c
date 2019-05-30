/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:55:25 by yhliboch          #+#    #+#             */
/*   Updated: 2018/12/22 17:25:23 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*copy_to_big(char *dst, char *src, int side)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (src[i])
	{
		while (src[i] == '#')
		{
			dst[j] = '#';
			i++;
			j++;
		}
		while ((j % (side + 1)) != 0)
			j++;
		while ((i % 5) != 0)
			i++;
		while (src[i] != '#' && src[i] != '\0')
		{
			i++;
			j++;
		}
	}
	return (dst);
}

void		next_pos(int *pos, char *work)
{
	int				i;
	int				tmp;

	i = 0;
	tmp = 0;
	while (i < 4)
	{
		work[pos[i]] = '.';
		i++;
	}
	i = -1;
	while (++i < 4)
		pos[i] += 1;
	while (work[pos[0]] == '\n' || work[pos[1]] == '\n' ||
	work[pos[2]] == '\n' || work[pos[3]] == '\n')
	{
		pos[0] += 1;
		pos[1] += 1;
		pos[2] += 1;
		pos[3] += 1;
	}
	i = -1;
	while (++i < 4)
		work[pos[i]] = '#';
}

int			*coordinates(int *pos, char *work)
{
	int			*res;
	int			nl;
	int			i;

	i = 0;
	nl = 0;
	res = (int *)malloc(sizeof(int) * 4 + 1);
	while (i < 4)
	{
		while (*work != '#')
		{
			if (*work == '\n')
				nl++;
			work++;
		}
		res[i] = pos[i] - nl;
		work++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

t_matrix	*combinations(t_matrix **start, char *str, int side)
{
	int			end;
	int			*pos;
	char		*work;
	static int	letter;
	t_matrix	*start1;

	start1 = *start;
	if (g_side < side && (letter = 65))
		g_side = side;
	work = empty_square(side);
	work = copy_to_big(work, str, side);
	end = side * side + side;
	pos = cor(work);
	while (pos[3] < end)
	{
		if (check_symb(work, side) == 1 && check_relations(work, side) == 1)
			make_row(start1->right, coordinates(pos, work), letter);
		next_pos(pos, work);
	}
	letter++;
	free(work);
	free(pos);
	return (*start);
}
