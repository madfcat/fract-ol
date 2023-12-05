/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:31:04 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/05 19:12:21 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_handle_close(t_state *state)
{
	ft_putstr_fd("Bye-bye!\n", 1);
	mlx_destroy_window(state->mlx, state->win);
	exit(0);
	return (0);
}

void	ft_handle_more_controls(int key, t_state *state)
{
	if (key == 53)
		ft_handle_close(state);
	if (key == KEY_UP)
	{
		state->top += 10 * state->y_step;
		state->bottom += 10 * state->y_step;
	}
	if (key == KEY_DOWN)
	{
		state->top -= 10 * state->y_step;
		state->bottom -= 10 * state->y_step;
	}
	if (key == KEY_LEFT)
	{
		state->left -= 10 * state->x_step;
		state->right -= 10 * state->x_step;
	}
	if (key == KEY_RIGHT)
	{
		state->left += 10 * state->x_step;
		state->right += 10 * state->x_step;
	}
}

void	ft_handle_numbers(int key, t_state *state)
{
	if (key == KEY_1)
	{
		state->type = "julia";
		state->ft_check_point = ft_check_point_julia;
	}
	if (key == KEY_2)
	{
		state->type = "mandelbrot";
		state->ft_check_point = ft_check_point_mandelbrot;
	}
	if (key == KEY_3)
	{
		state->type = "tricorn";
		state->ft_check_point = ft_check_point_tricorn;
	}
	if (key == KEY_4)
	{
		state->type = "ship";
		state->ft_check_point = ft_check_point_ship;
	}
	if (key == KEY_5)
	{
		state->type = "baldelbrot";
		state->ft_check_point = ft_check_point_baldelbrot;
	}
}

int	ft_handle_control(int key, t_state *state)
{
	state->zoom = 1;
	ft_handle_more_controls(key, state);
	if (key == KEY_X)
		state->color1 -= 9999;
	if (key == KEY_C)
		state->pause = abs(state->pause - 1);
	if (key == KEY_V)
		state->color1 += 9999;
	if (key == KEY_MINUS)
		state->cx -= 0.01;
	if (key == KEY_EQUAL)
		state->cx += 0.01;
	if (key == KEY_BRACKET_L)
		state->cy -= 0.01;
	if (key == KEY_BRACKET_R)
		state->cy += 0.01;
	if (key == KEY_A)
		state->scale += 0.01;
	if (key == KEY_S)
		state->scale -= 0.01;
	ft_handle_numbers(key, state);
	return (0);
}

int	ft_handle_mouse(int key, int x, int y, t_state *state)
{
	if (key == 1)
	{
		state->left -= (state->width / 2 - x) * state->x_step;
		state->right -= (state->width / 2 - x) * state->x_step;
		state->top += (state->height / 2 - y) * state->y_step;
		state->bottom += (state->height / 2 - y) * state->y_step;
		state->zoom = 1;
		ft_output_fractal(state);
	}
	if (key == 4)
	{
		state->prev_zoom = state->zoom;
		state->zoom = 1.3;
		state->zoom_count += 1;
		ft_output_fractal(state);
	}
	if (key == 5)
	{
		state->prev_zoom = state->zoom;
		state->zoom = 1 / 1.3;
		state->zoom_count -= 1;
		ft_output_fractal(state);
	}
	return (0);
}
