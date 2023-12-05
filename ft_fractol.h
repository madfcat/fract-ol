/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:31:12 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/05 20:32:44 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include "mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

typedef int	(*t_ft)();

typedef struct s_state {
	char	*type;
	void	*mlx;
	void	*win;
	double	width;
	double	height;
	double	zoom;
	double	prev_zoom;
	int		zoom_count;
	int		mouse_x;
	int		mouse_y;

	double	x_step;
	double	y_step;
	double	prev_x_step;
	double	prev_y_step;

	int		iter;
	int		max_iter;

	double	left;
	double	right;
	double	top;
	double	bottom;

	int		color1;
	int		color2;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;

	int		frame;
	int		pause;

	double	cx;
	double	cy;

	double	scale;

	t_ft	ft_check_point;
}				t_state;

enum {
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_X = 7,
	KEY_C = 8,
	KEY_V = 9,
	KEY_MINUS = 27,
	KEY_EQUAL = 24,
	KEY_BRACKET_L = 33,
	KEY_BRACKET_R = 30,
	KEY_A = 0,
	KEY_S = 1,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
};

int			ft_handle_close(t_state *state);
void		ft_handle_more_controls(int key, t_state *state);
int			ft_handle_control(int key, t_state *state);
int			ft_handle_mouse(int key, int x, int y, t_state *state);
void		ft_zoom_fractal(t_state *state);
void		ft_print_stats(t_state	*state);
void		ft_wrong_args(void);
void		ft_instructions(void);
int			render_next_frame(t_state *state);
void		ft_output_fractal(t_state	*state);
int			ft_check_point_julia(t_state *state, double x, double y);
int			ft_check_point_mandelbrot(t_state *state, double x0, double y0);
int			ft_check_point_tricorn(t_state *state, double x, double y);
int			ft_check_point_ship(t_state *state, double x, double y);
int			ft_check_point_baldelbrot(t_state *state, double x, double y);
void		ft_iter_pixels(t_state *state);
void		ft_output_fractal(t_state	*state);
int			render_next_frame(t_state *state);
void		custom_mlx_pixel_put(t_state *state, int x, int y, int color);
double		ft_atod(const char *str);
void		ft_init_struct(t_state	*state);
void		ft_init_mlx(t_state *state);

#endif