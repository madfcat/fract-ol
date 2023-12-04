/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:31:12 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/04 13:43:05 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
// # include <mlx.h>
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h> // remove later
# include <math.h>
# include "libft/libft.h"

// Define a function signature
typedef int	(*t_ft)();

typedef struct s_state {
	void	*mlx;
	void	*win;
	double	width;
	double	height;
	double	zoom;
	double	prev_zoom;
	int		zoom_count;
	int		mouse_x;
	int		mouse_y;
	int		prev_mouse_x;
	int		prev_mouse_y;

	int		diff;

	double	x_step;
	double	y_step;
	double	prev_x_step;
	double	prev_y_step;

	int		iter;

	double	left;
	double	right;
	double	top;
	double	bottom;

	int		color1;
	int		color2;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		frame;
	int		pause;
	int		fix;

	//Julia
	double	cx;
	double	cy;

	t_ft	ft_check_point;
}				t_state;

void	ft_mandelbrot(t_state	*state);
int		render_next_frame(t_state *state);
void	ft_output_fractal(t_state	*state);
// void	ft_freeall(t_state *state);
void ft_print_white(double curr_d[2], double curr_e[2], double curr_f[2], t_state *state);

#endif