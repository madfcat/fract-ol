/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:53:05 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/05 19:04:30 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_zoom_fractal(t_state *state)
{
	double	coord_x;
	double	coord_y;

	mlx_mouse_get_pos(state->win, &state->mouse_x, &state->mouse_y);
	state->x_step = (state->right - state->left) / state->zoom / state->height;
	state->y_step = (state->top - state->bottom) / state->zoom / state->height;
	state->left = state->left / state->zoom;
	state->right = state->right / state->zoom;
	state->top = state->top / state->zoom;
	state->bottom = state->bottom / state->zoom;
	coord_y = state->top * state->zoom - state->mouse_y * state-> prev_y_step;
	coord_x = state->right * state->zoom
		- (state->width - state->mouse_x) * state-> prev_x_step;
	if (state->prev_y_step || state->prev_x_step)
	{
		state->top = state->mouse_y * state->y_step + coord_y;
		state->bottom = state->top - state->height * state->y_step;
		state->right = (state->width - state->mouse_x)
			* state->x_step + coord_x;
		state->left = state->right - state->width * state->x_step;
	}
}

void	ft_iter_pixels(t_state *state)
{
	double	curr_x;
	double	curr_y;
	int		px_x;
	int		px_y;

	px_x = 0;
	curr_x = state->left;
	curr_y = state->top;
	while (px_x < state->width)
	{
		px_y = -1;
		curr_y = state->top;
		while (++px_y < state->height)
		{
			state->iter = state->ft_check_point(state, curr_x, curr_y);
			if (state->iter == 90)
				custom_mlx_pixel_put(state, px_x, px_y, state->color2);
			else
				custom_mlx_pixel_put(state, px_x, px_y,
					state->color1 * state->iter / 10);
			curr_y -= state->y_step;
		}
		px_x += 1;
		curr_x += state->x_step;
	}
}

void	ft_output_fractal(t_state	*state)
{
	ft_zoom_fractal(state);
	mlx_clear_window(state->mlx, state->win);
	ft_iter_pixels(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img, 0, 0);
	ft_print_stats(state);
	state->prev_x_step = state->x_step;
	state->prev_y_step = state->y_step;
}

int	render_next_frame(t_state *state)
{
	if (!state->pause)
	{
		state->frame += 1;
		if (state->frame % 5 == 0)
			state->color1 += 9999;
		ft_output_fractal(state);
		state->zoom = 1;
	}
	else
	{
		state->pause = 1;
		state->zoom = 1;
		ft_output_fractal(state);
	}
	return (0);
}
