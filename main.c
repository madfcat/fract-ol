/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:14:07 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/02 17:56:41 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

• open, close, read, write, malloc, free, perror, strerror, exit
• All functions of the math library (-lm compiler option, man man 3 math)
• All functions of the MiniLibX
• ft_printf and any equivalent YOU coded

https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
https://gontjarow.github.io/MiniLibX/

*/


#include "ft_fractol.h"

void	custom_mlx_pixel_put(t_state *state, int x, int y, int color)
{
	char	*dst;

	dst = state->addr + (y * state->line_length + x * (state->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// man /usr/share/man/man3/mlx.1

// void	ft_handle_key(void *mlx_ptr, void *win_ptr )
// {
// 	mlx_destroy_window (mlx_ptr, win_ptr);
// 	exit(0);
// }

/*
Table of keys
esc
53

`		1		2		3		4		5		6		7		8		9		0		-		=
50		18		19		20		21		23		22		26		28		25		29		27		24

tab		q		w		e		r		t		y		u		i		o		p		[		]		\
48		12		13		14		15		17		16		32		34		31		35		33		30		42

a		s		d		f		g		h		j		k		l		;		'		enter
0		1		2		3		5		4		38		40		37		41		39		36

shift	z		x		c		v		b		n		m		,		.		/		shift
257		6		7		8		9		11		45		46		43		47		44		258

ctrl	opt		cmd		space	cmd		opt		ctrl
256		261		259		49		260		262		269

		up
		126
left	down	right
123		125		124

scroll down		scroll up
5				4
*/

int	ft_handle_key(int key, t_state *state)
{
	ft_putnbr_fd(key, 1);
	if (key == 53)
	{
		ft_putstr_fd("Bye-bye\n", 1);
		mlx_destroy_window(state->mlx, state->win);
		// ft_freeall(state);
		exit(0);
	}
	state->zoom = 1;
	if (key == 126)
	{
		state->top += 10*state->y_step;
		state->bottom += 10*state->y_step;
	}
	if (key == 125)
	{
		state->top -= 10*state->y_step;
		state->bottom -= 10*state->y_step;
	}
	if (key == 123)
	{
		state->left -= 10*state->x_step;
		state->right -= 10*state->x_step;
	}
	if (key == 124)
	{
		state->left += 10*state->x_step;
		state->right += 10*state->x_step;
	}
	ft_output_fractal(state);
	return (0);
}

int	ft_handle_close(t_state *state)
{
	(void )state;
	// ft_putnbr_fd(key, 1);
	ft_putstr_fd("Bye-bye\n", 1);
	// mlx_destroy_image(state->mlx, state->img);
	// mlx_destroy_window(state->mlx, state->win);
	// ft_freeall(state);
	exit(0);
	return (0);
}

int	ft_handle_mouse(int key, int x, int y, void *param)
{
	(void)x;
	(void)y;
	// double z;
	t_state	*state = param;
	ft_putnbr_fd(key, 1);
	ft_putstr_fd("\n", 1);

	// mlx_string_put(state->mlx, state->win, 50, 50, 0xFFFFFF, "Hello, MiniLibX!");
 	if (key == 4)
	{
		// mlx_clear_window(state->mlx, state->win);
		state->prev_zoom = state->zoom;
		// state->zoom *= 1.1;
		state->zoom = 1.3;
		state->zoom_count += 1;
		// z = 1.5;
		// ft_putnbr_fd(state->zoom2, 1);
		printf("Zoom = %f\n", state->zoom);
		// ft_putstr_fd(hello, 1);
		ft_putstr_fd("Scroll up!\n", 1);
		ft_output_fractal(state);
	}
	if (key == 5)
	{
		// mlx_clear_window(state->mlx, state->win);
		state->prev_zoom = state->zoom;
		// state->zoom /= 1.1;
		state->zoom = 1/1.3;
		state->zoom_count -= 1;
		// state->mouse_y = y;
		// z = 1.5;
		// ft_putnbr_fd(state->zoom2, 1);
		printf("Zoom = %f\n", state->zoom);
		// ft_putstr_fd(hello, 1);
		ft_putstr_fd("Scroll down!\n", 1);
		ft_output_fractal(state);
	}
	return (0);
}

// void	ft_freeall(t_state *state)
// {
// 	(void)state;
// 	// mlx_clear_window(state->mlx, state->win);
// 	// mlx_destroy_window(state->mlx, state->win);
// 	// free(state->mlx);
// 	// free(state->win);
// 	// free(state->img);
// }

/*
for each pixel (Px, Py) on the screen do
    x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
    y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))
    x := 0.0
    y := 0.0
    iteration := 0
    max_iteration := 1000
    while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
        xtemp := x*x - y*y + x0
        y := 2*x*y + y0
        x := xtemp
        iteration := iteration + 1
 
    color := palette[iteration]
    plot(Px, Py, color)
*/

// double	ft_abs(double n)
// {
// 	if (n < 0)
// 		n = -n;
// 	return (n);
// }


void	ft_print_stats(t_state	*state)
{
	char	*zoom_text;
	char	*temp;

	temp = ft_itoa(state->zoom_count);
	zoom_text = ft_strjoin("Zoom: ", temp);
	mlx_string_put(state->mlx, state->win, 20, 40, 0xFFFFFF, zoom_text);
	free(zoom_text);
	free(temp);
}

void	ft_zoom_fractal(t_state *state)
{
	double	coord_x;
	double	coord_y;

	state->prev_mouse_x = state->mouse_x;
	state->prev_mouse_y = state->mouse_y;

	// state->mouse_x = x;
	// state->mouse_y = y;
	mlx_mouse_get_pos(state->win, &state->mouse_x, &state->mouse_y);
	printf("X: %d", state->mouse_x);
	printf("Y: %d", state->mouse_y);
	printf("Zoom count: %d\n", state->zoom_count);
	printf("Top: %f\n", state->top);

	state->x_step = (state->right - state->left) / state->zoom / state->height;
	state->y_step = (state->top - state->bottom) / state->zoom / state->height;

	state->left = state->left / state->zoom;
	state->right = state->right / state->zoom;
	state->top = state->top / state->zoom;
	state->bottom = state->bottom / state->zoom;

	coord_y = state->top * state->zoom - state->mouse_y * state-> prev_y_step;
	coord_x = state->right * state->zoom - (state->width - state->mouse_x) * state-> prev_x_step;

	printf("Prev_y_step: %f\n", state->prev_y_step);
	// if (state->prev_y_step && state->mouse_y && state->mouse_y < state->height / 2)
	if (state->prev_y_step || state->prev_x_step)
	{
		state->top = state->mouse_y * state->y_step + coord_y;
		state->bottom = state->top - state->height*state->y_step;
		state->right = (state->width - state->mouse_x) * state->x_step + coord_x;
		state->left = state->right - state->width*state->x_step;
	}
}

int	ft_check_point(double x0, double y0)
{
	double	x;
	double	y;
	int		iter;
	double	x_temp;

	x = 0;
	y = 0;
	iter = 0;
	while (x * x + y * y <= 2 * 2 && iter < 90)
	{
		x_temp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = x_temp;
		iter += 1;
	}
	return (iter);
}

void	ft_mandelbrot(t_state	*state)
{
	double	curr_x;
	double	curr_y;
	// double	x_step;
	// double	y_step;
	int		px_x;
	int		px_y;
	int color2;

	px_x = 0;
	px_y = 0;
	curr_x = state->left;
	curr_y = state->top;
	color2 = 0xFFFFFFFF;

	while (px_x < state->width)
	{
		px_y = 0;
		curr_y = state->top;
		while (px_y < state->height)
		{
			// if (px_y > state->height / 2)
			// 	custom_mlx_pixel_put(img, px_x, px_y, color2);
			int iter = ft_check_point(curr_x, curr_y);
			if (ft_check_point(curr_x, curr_y) == 90)
				custom_mlx_pixel_put(state, px_x, px_y, color2);
			else
				// custom_mlx_pixel_put(state, px_x, px_y, state->color1 + iter*iter*1000);
				custom_mlx_pixel_put(state, px_x, px_y, state->color1 * iter);
			px_y += 1;
			// color += 1;
			curr_y -= state->y_step;
		}
		// color += 0x00010000;
		px_x += 1;
		curr_x += state->x_step;
	}
}

// R = escape radius  # choose R > 0 such that R**2 - R >= sqrt(cx**2 + cy**2)

// for each pixel (x, y) on the screen, do:   
// {
//     zx = scaled x coordinate of pixel; # (scale to be between -R and R)
//        # zx represents the real part of z.
//     zy = scaled y coordinate of pixel; # (scale to be between -R and R)
//        # zy represents the imaginary part of z.

//     iteration = 0;
//     max_iteration = 1000;
  
//     while (zx * zx + zy * zy < R**2  AND  iteration < max_iteration) 
//     {
//         xtemp = zx * zx - zy * zy;
//         zy = 2 * zx * zy  + cy;
//         zx = xtemp + cx;
    
//         iteration = iteration + 1;
//     }
  
//     if (iteration == max_iteration)
//         return black;
//     else
//         return iteration;
// }

int	ft_check_point_j(double x, double y)
{
	// double	x;
	// double	y;
	int		iter;
	double	x_temp;
	double r = 7.5;
	double cx = -0.835;
	double cy = -0.321;
	double r2 = sqrt(cx*cx + cy*cy) + r + 3;

	// printf("R2: %f\n", r2);
	iter = 0;
	while (x * x + y * y <= r2 && iter < 90)
	{
		x_temp = x * x - y * y;
		y = 2 * x * y + cy;
		x = x_temp + cx;
		iter += 1;
	}
	// printf("Iter: %d\n", iter);
	return (iter);
}

void	ft_julia(t_state	*state)
{
	double	curr_x;
	double	curr_y;
	int		px_x;
	int		px_y;
	int color2;

	px_x = 0;
	px_y = 0;
	curr_x = state->left;
	curr_y = state->top;
	color2 = 0x00000000;

	while (px_x < state->width)
	{
		px_y = 0;
		curr_y = state->top;
		while (px_y < state->height)
		{
			int iter = ft_check_point_j(curr_x, curr_y);
			if (iter == 90)
				custom_mlx_pixel_put(state, px_x, px_y, color2);
			else
				custom_mlx_pixel_put(state, px_x, px_y, state->color1 + iter * iter * 1000);
			px_y += 1;
			curr_y -= state->y_step;
		}
		// color += 0x00010000;
		px_x += 1;
		curr_x += state->x_step;
	}
}

void	ft_output_fractal(t_state	*state)
{
	ft_zoom_fractal(state);
	mlx_clear_window(state->mlx, state->win);
	// ft_mandelbrot(state);
	ft_julia(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img, 0, 0);
	ft_print_stats(state);
	state->prev_x_step = state->x_step;
	state->prev_y_step = state->y_step;
}
// 4294967295
// 1000000000

int	render_next_frame(t_state *state)
{
	(void)state;
	state->color1 += 1;
	ft_output_fractal(state);
	state->zoom = 1;
	return (0);
}

int	main(void)
{
	t_state	state;

	state.width = 400;
	state.height = 400;
	state.zoom = 1;
	state.mouse_x = 0;
	state.mouse_y = 0;
	// state.zoom = 1.1;
/* 	// Mandelbrot
	state.left = -2.00;
	state.right = 2.00;
	state.top = 2.00;
	state.bottom = -2.00; */
	//Julia
	state.left = -3.50;
	state.right = 3.50;
	state.top = 3.50;
	state.bottom = -3.50;
	
	state.zoom_count = 0;
	state.prev_x_step = 0;
	state.prev_y_step = 0;
	state.color1 = 0x00000000;

	state.mlx = mlx_init();
	if (!state.mlx)
		exit(0);
	state.win = mlx_new_window(state.mlx, state.width, state.height, "Fract-ol");
	if (!state.win)
	{
		free(state.mlx);
		exit(0);
	}
	state.img = mlx_new_image(state.mlx, state.width, state.height);
	if (!state.img)
	{
		free(state.mlx);
		free(state.win);
		exit(0);
	}
	state.addr = mlx_get_data_addr(state.img, &state.bits_per_pixel, &state.line_length,
								&state.endian);
								/*
	custom_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	custom_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	custom_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	custom_mlx_pixel_put(&img, 5, 8, 0x00FF0000);
	custom_mlx_pixel_put(&img, 5, 9, 0x00FF0000);
	custom_mlx_pixel_put(&img, 5, 10, 0x00FF0000);
								*/
	// mlx_put_image_to_window(state.mlx, state.win, state.img, 0, 0);
	ft_output_fractal(&state);

	// Pressing ESC must close the window and quit the program in a clean way.
	mlx_key_hook(state.win, ft_handle_key, &state);
	// Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
	mlx_hook(state.win, 17, 0L, ft_handle_close, &state);
	
	mlx_mouse_hook(state.win, ft_handle_mouse, &state);


	mlx_loop_hook(state.mlx, render_next_frame, &state);
	mlx_loop(state.mlx);

	// ft_freeall(&state);
	return (0);
}

/*
       void *
       mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

       int
       mlx_clear_window ( void *mlx_ptr, void *win_ptr );

       int
       mlx_destroy_window ( void *mlx_ptr, void *win_ptr );

*/