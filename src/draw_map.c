/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:22:00 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/07 16:22:00 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			draw_hor_line(t_draw *win, t_coord *coord, int k)
{
	t_print		*pr;

	pr = ft_memalloc(sizeof(t_print));
	pr->x0 = coord[k].x + 100;
	pr->x1 = coord[k + 1].x + 100;
	pr->y0 = coord[k].y + 100;
	pr->y1 = coord[k + 1].y + 100;
	if (win->z[k] == 0)
		create_line(pr, win, 1);
	else
		create_line(pr, win, 2);
	free(pr);
}

void			draw_ver_line(t_draw *win, t_coord *coord, int k)
{
	t_print		*pr;

	pr = ft_memalloc(sizeof(t_print));
	pr->x0 = coord[k].x + 100;
	pr->x1 = coord[k + win->count_diggits].x + 100;
	pr->y0 = coord[k].y + 100;
	pr->y1 = coord[k + win->count_diggits].y + 100;
	if (win->z[k] == 0)
		create_line(pr, win, 1);
	else
		create_line(pr, win, 2);
	free(pr);
}

void			ft_draw_map(t_draw *win, t_coord *coord)
{
	int		k;

	k = 0;
	while (k < win->count_str * win->count_diggits)
	{
		if (k % win->count_diggits < win->count_diggits - 1)
			draw_hor_line(win, coord, k);
		if (k + win->count_diggits < win->count_str * win->count_diggits)
			draw_ver_line(win, coord, k);
		k++;
	}
	if (win->z[k - 1] == 0)
		mlx_pixel_put(win->mlx, win->window, coord[k - 1].x + 100,\
						coord[k - 1].y + 100, 0x024ecc);
	else
		mlx_pixel_put(win->mlx, win->window, coord[k - 1].x + 100,\
						coord[k - 1].y + 100, 0xffffff);
	mlx_hook(win->window, 2, 0, push_key, win);
}

void			free_all(t_draw *win)
{
	system("killall afplay");
	if (win->map)
		free_map(win);
	free(win->z);
	free(win->help);
	free(win->coord);
	free(win->name);
	free(win);
}
