/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:04:16 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/19 17:04:17 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		push_key(int key, t_draw *win)
{
	push_key1(key, win);
	push_key2(key, win);
	push_key3(key, win);
	push_key5(key, win);
	if (key == 125 && (win->coord[0].y + 2 * win->step + 100 < 11300) &&\
			(win->coord[(win->count_str - 1) * (win->count_diggits)].y + 2 *\
			win->step + 100 < 11300) && (win->coord[win->count_diggits - 1].y)\
			+ 2 * win->step + 100 < 11300 && (win->coord[win->count_str *\
			win->count_diggits - 1].y + 2 * win->step + 100 < 11300))
	{
		mlx_clear_window(win->mlx, win->window);
		ft_move(win, 2);
	}
	push_key4(key, win);
	return (0);
}

int		push_key1(int key, t_draw *win)
{
	if (key == 53)
	{
		free_all(win);
		exit(0);
	}
	else if (key == 12)
	{
		if (win->start[0] == 0 && win->start[1] == 0)
		{
			mlx_clear_window(win->mlx, win->window);
			turn(win, 1, 1);
		}
	}
	else if (key == 13)
	{
		if (win->start[0] == 0 && win->start[1] == 0)
		{
			mlx_clear_window(win->mlx, win->window);
			turn(win, 2, 1);
		}
	}
	return (0);
}

int		push_key2(int key, t_draw *win)
{
	if (key == 14)
	{
		if (win->start[0] == 0 && win->start[1] == 0)
		{
			mlx_clear_window(win->mlx, win->window);
			turn(win, 3, 1);
		}
	}
	else if (key == 0)
	{
		if (win->start[0] == 0 && win->start[1] == 0)
		{
			mlx_clear_window(win->mlx, win->window);
			turn(win, 1, -1);
		}
	}
	else if (key == 1)
	{
		if (win->start[0] == 0 && win->start[1] == 0)
		{
			mlx_clear_window(win->mlx, win->window);
			turn(win, 2, -1);
		}
	}
	return (0);
}

int		push_key3(int key, t_draw *win)
{
	if (key == 2)
	{
		if (win->start[0] == 0 && win->start[1] == 0)
		{
			mlx_clear_window(win->mlx, win->window);
			turn(win, 3, -1);
		}
	}
	else if (key == 36)
	{
		mlx_clear_window(win->mlx, win->window);
		FREETHREE(win->coord, win->help, win->z);
		ft_create_map(win);
	}
	else if (key == 24)
	{
		mlx_clear_window(win->mlx, win->window);
		ft_change_scale(win, 1);
	}
	else if (key == 27)
	{
		mlx_clear_window(win->mlx, win->window);
		ft_change_scale(win, 0);
	}
	return (0);
}

int		push_key4(int key, t_draw *win)
{
	if (key == 126 && (win->coord[0].y - 2 * win->step + 100 > -5000) &&\
			(win->coord[(win->count_str - 1) * (win->count_diggits)].y\
			- 2 * win->step + 100 > -5000) && (win->coord[win->count_diggits\
			- 1].y) - 2 * win->step + 100 > -5000 && (win->coord[win->count_str\
			* win->count_diggits - 1].y - 2 * win->step + 100 > -5000))
	{
		mlx_clear_window(win->mlx, win->window);
		ft_move(win, -2);
	}
	mlx_string_put(win->mlx, win->window, 1900, 10, 0x9b0000,
				"menu");
	mlx_string_put(win->mlx, win->window, 1900, 25, 0x9b0000,
				"press q, a, w, s, e, d to rotate");
	mlx_string_put(win->mlx, win->window, 1900, 40, 0x9b0000,
				"press arrows to move a map");
	mlx_string_put(win->mlx, win->window, 1900, 55, 0x9b0000,
				"press +- to change scale");
	mlx_string_put(win->mlx, win->window, 1900, 70, 0x9b0000,
				"press enter to reset");
	mlx_string_put(win->mlx, win->window, 1900, 85, 0x9b0000,
				"press ESC to exit");
	return (0);
}
