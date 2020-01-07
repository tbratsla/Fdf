/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:38:03 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/04 15:38:04 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_start(char *av, int fd)
{
	t_draw	*win;

	win = ft_memalloc(sizeof(t_draw));
	ft_read_file(fd, win);
	close(fd);
	win->step = 100;
	while (win->step * win->count_diggits + 100 > 2280 ||\
		win->step * win->count_str + 100 > 1300)
		win->step /= 1.1;
	win->name = ft_strjoin("Fdf with map ", av);
	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, 2280, 1300, win->name);
	mlx_string_put(win->mlx, win->window, 1900, 100,\
		0x9b0000, "press some key");
	ft_create_map(win);
	system("afplay sound.mp3&");
	mlx_loop(win->mlx);
}

int		main(int ac, char **av)
{
	int		fd;
	int		fd1;

	if (ac != 2)
	{
		ft_putendl("Incorrect number of parameters! Please try again)");
		ft_putendl("usage: ./fdf sample_file");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) <= 0)
	{
		perror("Oh, no");
		close(fd);
		return (0);
	}
	if ((fd1 = open(av[1], O_DIRECTORY)) > 0)
	{
		ft_putendl("Are you crazy? Give me a valid map!");
		close(fd);
		close(fd1);
		return (0);
	}
	ft_start(av[1], fd);
	return (0);
}

int		ft_count_str(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		ft_count_diggits(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

void	ft_create_map(t_draw *win)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	win->coord = ft_memalloc(sizeof(t_coord) *\
			win->count_str * win->count_diggits);
	win->help = ft_memalloc(sizeof(t_coord) *\
			win->count_str * win->count_diggits);
	win->z = ft_memalloc(sizeof(int) * win->count_str * win->count_diggits);
	while (i < win->count_str)
	{
		read_coord(win, i, &k);
		i++;
	}
	win->start[0] = 0;
	win->start[1] = 0;
	ft_draw_map(win, win->coord);
}
