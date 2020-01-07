/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:48:47 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/07 15:48:48 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void		ft_read_file(int fd, t_draw *win)
{
	char	*buf;
	char	*str;
	char	*help;
	int		ret;

	buf = ft_strnew(BUF_SIZE);
	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		help = str;
		str = ft_strjoin(help, buf);
		free(help);
		if (ft_strlen(str) > 70000)
		{
			ft_putendl("Too big map");
			free(str);
			free(buf);
			exit(0);
		}
	}
	ft_strtoint(str, win);
	free(str);
	free(buf);
}

void		ft_strtoint(char *str, t_draw *win)
{
	int		i;
	int		k;
	int		a;

	// ZERO(a, k, i);
	// COUNT(win->count_str, win->count_diggits);
	a = 0;
	k = 0;
	i = 0;
	win->count_str = ft_count_str(str);
	win->count_diggits = ft_count_diggits(str);
	if (!(win->count_str) || !(win->count_diggits) || str[ft_strlen(str) - 1] !=
'\n' || (str[ft_strlen(str) - 1] == '\n' && str[ft_strlen(str) - 2] == '\n'))
		EXIT1;
	if (win->count_diggits < 2)
		EXIT2;
	win->map = ft_memalloc(sizeof(int *) * win->count_str);
	while (str[k])
	{
		if (str[k] == '\n')
		{
			k++;
			if (!str[k])
				return ;
		}
		win->map[i] = ft_memalloc(sizeof(int *) * win->count_diggits);
		read_write(win, str, i, &k);
		PLUS;
	}
}

void		read_write(t_draw *win, char *str, int i, int *k)
{
	int		j;

	j = 0;
	while (str[*k] != '\n' && str[*k] != '\0')
	{
		if ((str[*k] >= '0' && str[*k] <= '9') || str[*k] == '-')
		{
			ft_bignum(str, win, *k);
			win->map[i][j] = ft_atoi(&str[*k]);
			while (str[*k] && str[*k] != ' ' && str[*k] != '\n'\
				&& str[*k] != '\t')
				(*k)++;
			(*k)--;
			j++;
		}
		(*k)++;
	}
	if (j != win->count_diggits)
	{
		free_map(win);
		free(win);
		ft_putendl("error");
		exit(0);
	}
}

void		ft_bignum(char *str, t_draw *win, int k)
{
	int		a;

	a = k;
	while (str[a] && str[a] >= '0' && str[a] <= '9')
	{
		a++;
		if (a - k > 5)
		{
			free_map(win);
			free(win);
			ft_putendl("Too big number");
			exit(0);
		}
	}
}

void		free_map(t_draw *win)
{
	int i;

	i = 0;
	while (i < win->count_str)
	{
		free(win->map[i]);
		i++;
	}
	free(win->map);
	win->map = 0;
}
