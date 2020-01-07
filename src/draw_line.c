/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:56:57 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/19 15:56:58 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	void	vertical_line(t_draw *win, t_print *pr, int i)
{
	int err;
	int	sign_x;
	int	sign_y;
	int del_x;
	int del_y;

	sign_y = pr->y1 >= pr->y0 ? 1 : -1;
	sign_x = pr->x1 >= pr->x0 ? 1 : -1;
	del_x = abs(pr->x1 - pr->x0);
	del_y = abs(pr->y1 - pr->y0);
	err = -del_y;
	while (pr->x0 != pr->x1 || pr->y0 != pr->y1)
	{
		if (i == 1)
			mlx_pixel_put(win->mlx, win->window, pr->x0, pr->y0, 0x024ecc);
		else
			mlx_pixel_put(win->mlx, win->window, pr->x0, pr->y0, 0xffffff);
		pr->y0 += sign_y;
		err += 2 * del_x;
		if (err > 0)
		{
			err -= 2 * del_y;
			pr->x0 += sign_x;
		}
	}
}

static	void	horizontal_line(t_draw *win, t_print *pr, int i)
{
	int err;
	int	sign_y;
	int	sign_x;
	int del_x;
	int del_y;

	sign_y = pr->y1 >= pr->y0 ? 1 : -1;
	sign_x = pr->x1 >= pr->x0 ? 1 : -1;
	del_x = abs(pr->x1 - pr->x0);
	del_y = abs(pr->y1 - pr->y0);
	err = -del_x;
	while (pr->x0 != pr->x1 || pr->y0 != pr->y1)
	{
		if (i == 1)
			mlx_pixel_put(win->mlx, win->window, pr->x0, pr->y0, 0x024ecc);
		else
			mlx_pixel_put(win->mlx, win->window, pr->x0, pr->y0, 0xffffff);
		pr->x0 += sign_x;
		err += 2 * del_y;
		if (err > 0)
		{
			err -= 2 * del_x;
			pr->y0 += sign_y;
		}
	}
}

void			create_line(t_print *pr, t_draw *win, int i)
{
	int		del_x;
	int		del_y;

	del_x = abs(pr->x1 - pr->x0);
	del_y = abs(pr->y1 - pr->y0);
	if (i == 1)
		mlx_pixel_put(win->mlx, win->window, pr->x0, pr->y0, 0x024ecc);
	else
		mlx_pixel_put(win->mlx, win->window, pr->x0, pr->y0, 0xffffff);
	if (del_y <= del_x)
		horizontal_line(win, pr, i);
	else
		vertical_line(win, pr, i);
}
