/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:39:34 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/04 15:39:35 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# define BUF_SIZE 128
# define EXIT1 {ft_putendl("Invalid map"); exit(0);}
# define EXIT2 {ft_putendl("Too small map"); exit(0);}
# define EXIT3 {ft_putendl("error1"); exit(0);}
# define ZERO(a, b, c) a = 0; b = 0; c = 0;
# define COUNT(a, b) a = ft_count_str(str); b = ft_count_diggits(str);
# define PLUS i++; k++;
# define RES {reset(k, win); break ;}
# define FREETHREE(a, b, c) free(a); free(b); free(c);

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_print
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_print;

typedef struct		s_matrix
{
	double			matrix[3][3];
}					t_matrix;

typedef struct		s_draw
{
	int				**map;
	void			*mlx;
	void			*window;
	int				count_diggits;
	int				count_str;
	t_coord			*coord;
	t_coord			*help;
	t_matrix		*matr;
	char			*name;
	int				start[2];
	int				*z;
	int				step;
}					t_draw;

void				draw_hor_line(t_draw *win, t_coord *coord, int k);
void				draw_ver_line(t_draw *win, t_coord *coord, int k);
void				create_line(t_print *pr, t_draw *win, int i);
int					push_key(int key, t_draw *win);
void				ft_create_map(t_draw *win);
int					ft_count_diggits(char *str);
void				ft_read_file(int fd, t_draw *win);
void				ft_strtoint(char *str, t_draw *win);
int					ft_count_str(char *str);
void				ft_draw_map(t_draw *win, t_coord *coord);
void				turn(t_draw *win, int i, int j);
t_matrix			*create_matrx(t_matrix *matrx, int j, int k);
void				create_new_matr(t_draw *win, t_matrix *matrx);
void				ft_create_base_matr(t_draw *win);
t_matrix			*create_matry(t_matrix *matrx, int j, int k);
t_matrix			*create_matrz(t_matrix *matrx, int j, int k);
void				ft_get_new_coord(t_draw *win);
t_matrix			*create_matrs(t_matrix *matrx, double step);
void				ft_change_scale(t_draw *win, int i);
void				ft_move(t_draw *win, int i);
int					ft_check_map(int fd, t_draw *win, char *str);
void				ft_rewrite_matr(t_draw *win, double c[3][3]);
void				free_map(t_draw *win);
void				ft_bignum(char *str, t_draw *win, int k);
void				read_write(t_draw *win, char *str, int i, int *k);
int					push_key1(int key, t_draw *win);
int					push_key2(int key, t_draw *win);
int					push_key3(int key, t_draw *win);
int					push_key4(int key, t_draw *win);
int					push_key5(int key, t_draw *win);
void				reset(int k, t_draw *win);
void				get_new_coord1(t_draw *win, int k);
void				read_coord(t_draw *win, int i, int *k);
void				free_all(t_draw *win);

#endif
