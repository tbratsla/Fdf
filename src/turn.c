/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:02:41 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/11 17:02:42 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		turn(t_draw *win, int i, int j)
{
	t_matrix	*matrx;

	matrx = NULL;
	ft_create_base_matr(win);
	if (i == 1)
		matrx = create_matrx(matrx, j, 1);
	else if (i == 2)
		matrx = create_matry(matrx, j, 1);
	else if (i == 3)
		matrx = create_matrz(matrx, j, 1);
	create_new_matr(win, matrx);
	ft_get_new_coord(win);
	ft_draw_map(win, win->coord);
	free(win->matr);
	win->matr = 0;
}

t_matrix	*create_matrx(t_matrix *matrx, int j, int k)
{
	double a;

	a = 3.5 * (M_PI / 180) * j * k;
	matrx = ft_memalloc(sizeof(t_matrix));
	matrx->matrix[0][0] = 1;
	matrx->matrix[0][1] = 0;
	matrx->matrix[0][2] = 0;
	matrx->matrix[1][0] = 0;
	matrx->matrix[1][1] = cos(a);
	matrx->matrix[1][2] = -sin(a);
	matrx->matrix[2][0] = 0;
	matrx->matrix[2][1] = sin(a);
	matrx->matrix[2][2] = cos(a);
	return (matrx);
}

t_matrix	*create_matry(t_matrix *matrx, int j, int k)
{
	double a;

	a = 3.5 * (M_PI / 180) * j * k;
	matrx = ft_memalloc(sizeof(t_matrix));
	matrx->matrix[0][0] = cos(a);
	matrx->matrix[0][1] = 0;
	matrx->matrix[0][2] = sin(a);
	matrx->matrix[1][0] = 0;
	matrx->matrix[1][1] = 1;
	matrx->matrix[1][2] = 0;
	matrx->matrix[2][0] = -sin(a);
	matrx->matrix[2][1] = 0;
	matrx->matrix[2][2] = cos(a);
	return (matrx);
}

t_matrix	*create_matrz(t_matrix *matrx, int j, int k)
{
	double a;

	a = 3.5 * (M_PI / 180) * j * k;
	matrx = ft_memalloc(sizeof(t_matrix));
	matrx->matrix[0][0] = cos(a);
	matrx->matrix[0][1] = -sin(a);
	matrx->matrix[0][2] = 0;
	matrx->matrix[1][0] = sin(a);
	matrx->matrix[1][1] = cos(a);
	matrx->matrix[1][2] = 0;
	matrx->matrix[2][0] = 0;
	matrx->matrix[2][1] = 0;
	matrx->matrix[2][2] = 1;
	return (matrx);
}

void		create_new_matr(t_draw *win, t_matrix *matrx)
{
	int			i;
	int			j;
	int			k;
	double		c[3][3];

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			c[i][j] = 0;
			while (k < 3)
			{
				c[i][j] += win->matr->matrix[i][k] * matrx->matrix[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	ft_rewrite_matr(win, c);
	free(matrx);
}
