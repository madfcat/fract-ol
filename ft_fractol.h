/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:31:12 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/01 13:23:14 by vshchuki         ###   ########.fr       */
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

typedef struct	s_state	{
	void	*mlx;
	void	*win;
	float	width;
	float	height;
	float	zoom;
	float	prev_zoom;
	int		zoom_count;
	int		mouse_x;
	int		mouse_y;
	int		prev_mouse_x;
	int		prev_mouse_y;

	int		diff;

	float	x_step;
	float	y_step;
	float	prev_x_step;
	float	prev_y_step;

	float 	left;
	float	right;
	float	top;
	float	bottom;

	int color1;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_state;

void	ft_mandelbrot(t_state	*state, int x, int y);
int		render_next_frame(t_state *state);
// void	ft_freeall(t_state *state);

#endif