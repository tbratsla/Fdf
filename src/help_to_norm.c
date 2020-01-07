/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:02:49 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/19 16:02:50 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_rewrite_matr(t_draw *win, double c[3][3])
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			win->matr->matrix[i][j] = c[i][j];
			j++;
		}
		i++;
	}
}

int		push_key5(int key, t_draw *win)
{
	if ((key == 123) && (win->coord[0].x - 2 * win->step + 100 > -5000) &&\
		(win->coord[(win->count_str - 1) * (win->count_diggits)].x - 2 *\
		win->step + 100 > -5000) && (win->coord[win->count_diggits - 1].x)\
		- 2 * win->step + 100 > -5000 && (win->coord[win->count_str *\
		win->count_diggits - 1].x - 2 * win->step + 100 > -5000))
	{
		mlx_clear_window(win->mlx, win->window);
		ft_move(win, -1);
	}
	else if (key == 124 && (win->coord[0].x + 2 * win->step + 100 < 12280) &&\
		(win->coord[(win->count_str - 1) * (win->count_diggits)].x + 2 *\
		win->step + 100 < 12280) && (win->coord[win->count_diggits - 1].x)\
		+ 2 * win->step + 100 < 12280 && (win->coord[win->count_str *\
		win->count_diggits - 1].x + 2 * win->step + 100 < 12280))
	{
		mlx_clear_window(win->mlx, win->window);
		ft_move(win, 1);
	}
	return (0);
}

void	get_new_coord1(t_draw *win, int k)
{
	win->coord[k].x = win->help[k].x * win->matr->matrix[0][0] +\
	win->help[k].y * win->matr->matrix[0][1] + win->help[k].z *\
	win->matr->matrix[0][2];
	win->coord[k].y = win->help[k].x * win->matr->matrix[1][0] +\
	win->help[k].y * win->matr->matrix[1][1] + win->help[k].z *\
	win->matr->matrix[1][2];
	win->coord[k].z = win->help[k].x * win->matr->matrix[2][0] +\
	win->help[k].y * win->matr->matrix[2][1] + win->help[k].z *\
	win->matr->matrix[2][2];
}

void	ft_create_base_matr(t_draw *win)
{
	int i;
	int j;

	i = 0;
	win->matr = ft_memalloc(sizeof(t_matrix));
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			win->matr->matrix[i][j] = 0;
			if (i == j)
				win->matr->matrix[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	read_coord(t_draw *win, int i, int *k)
{
	int j;

	j = 0;
	while (j < win->count_diggits)
	{
		win->coord[*k].x = win->step * j;
		win->coord[*k].y = win->step * i;
		win->coord[*k].z = win->map[i][j] * 3;
		win->z[*k] = win->map[i][j];
		j++;
		(*k)++;
	}
}
