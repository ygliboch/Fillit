/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:18:06 by yhliboch          #+#    #+#             */
/*   Updated: 2018/12/22 17:24:40 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

int						g_side;
int						g_y;

int						*coordinates(int *pos, char *work);
int						*for_newlines(int nl, int *pos);
void					next_pos(int *pos, char *work);
char					*copy_to_big(char *dst, char *src, int side);
int						square_size(int num);
void					options(t_list **list, int num, int side);
char					*toleft(char *str);
void					hesh(char **new, char *str, int count);
char					*empty_square(int size);
int						*cor(char *str);
int						check_symb(char *str, int side);
int						check_relations(char *str, int side);
int						count_tetrim(char *str);
void					change_tetrim(char *str);
t_list					*check_tetrim(char *str, int side);

typedef struct			s_matrix
{
	struct s_matrix		*left;
	struct s_matrix		*right;
	struct s_matrix		*up;
	struct s_matrix		*down;
	struct s_matrix		*head;
	int					x;
	int					y;
}						t_matrix;

typedef struct			s_stack
{
	t_matrix			*matrix;
	struct s_stack		*next;
}						t_stack;

t_matrix				*make_start(t_matrix **start,
								t_list **list, int side, int num);
void					del_stack(t_stack **stack);
void					elem_del(t_matrix **elem);
void					matrix_del(t_matrix **start);
void					uncover_row(t_matrix *row);
void					uncover(t_stack **stack);
t_stack					*stacknew(t_matrix *row);
void					cover_row(t_matrix *row);
void					cover(t_matrix *row, t_stack **stack, t_matrix **start);
t_matrix				*make_hed(t_matrix **start, int num, int s);
void					make_square(t_stack *stack, int side, int num);
t_matrix				*give_row(t_matrix *start);
void					last_row(t_matrix *start);
int						work(t_matrix **start, t_stack **stack);
t_matrix				*create_elem(int x, int y);
void					make_row(t_matrix *work, int *cor, int letter);
void					make_row2(t_matrix *start,
								t_matrix *work, int y, int *cor);
t_matrix				*make_matrix(int *x, int letter, int s, int num);
t_matrix				*combinations(t_matrix **start, char *str, int side);

#endif
