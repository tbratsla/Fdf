/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:10:08 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/14 12:10:08 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_change_scale(t_draw *win, int i)
{
	t_matrix	*matrx;

	matrx = NULL;
	ft_create_base_matr(win);
	if (i == 1)
		matrx = create_matrs(matrx, 1.5);
	else if (i == 0)
		matrx = create_matrs(matrx, 0.66);
	create_new_matr(win, matrx);
	ft_get_new_coord(win);
	ft_draw_map(win, win->coord);
	free(win->matr);
}

void		ft_get_new_coord(t_draw *win)
{
	int			k;

	k = 0;
	while (k < win->count_str * win->count_diggits)
	{
		win->help[k].x = (win->coord[k].x / win->step\
					- (win->count_diggits / 2)) * win->step;
		win->help[k].y = (win->coord[k].y / win->step\
					- (win->count_str / 2)) * win->step;
		win->help[k].z = win->coord[k].z;
		get_new_coord1(win, k);
		win->coord[k].x += win->count_diggits / 2 * win->step;
		win->coord[k].y += win->count_str / 2 * win->step;
		if (win->coord[k].x + 100 > 12280 || win->coord[k].x + 100 < -5000 ||\
			win->coord[k].y + 100 < -5000 || win->coord[k].y + 100 > 11300)
			RES;
		k++;
	}
	k--;
	if (fabs(win->coord[k].x - win->coord[k - 1].x) < 0.001)
		reset(k, win);
}

void		ft_move(t_draw *win, int i)
{
	int		k;

	k = 0;
	if (i == 1 || i == -1)
	{
		while (k < win->count_str * win->count_diggits)
		{
			win->coord[k].x += win->step * i;
			win->start[0] += win->step * i;
			k++;
		}
		ft_draw_map(win, win->coord);
	}
	else if (i == -2 || i == 2)
	{
		while (k < win->count_str * win->count_diggits)
		{
			win->coord[k].y += win->step * i;
			win->start[0] += win->step * i;
			k++;
		}
		ft_draw_map(win, win->coord);
	}
}

t_matrix	*create_matrs(t_matrix *matrx, double step)
{
	matrx = ft_memalloc(sizeof(t_matrix));
	matrx->matrix[0][0] = step;
	matrx->matrix[0][1] = 0;
	matrx->matrix[0][2] = 0;
	matrx->matrix[1][0] = 0;
	matrx->matrix[1][1] = step;
	matrx->matrix[1][2] = 0;
	matrx->matrix[2][0] = 0;
	matrx->matrix[2][1] = 0;
	matrx->matrix[2][2] = step;
	return (matrx);
}

void		reset(int k, t_draw *win)
{
	while (k >= 0)
	{
		win->coord[k].x = win->help[k].x + win->count_diggits / 2 * win->step;
		win->coord[k].y = win->help[k].y + win->count_str / 2 * win->step;
		win->coord[k].z = win->help[k].z;
		k--;
	}
}
