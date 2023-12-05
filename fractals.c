/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:45:24 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/05 19:14:39 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_check_point_mandelbrot(t_state *state, double x0, double y0)
{
	double	x;
	double	y;
	int		iter;
	double	x_temp;

	(void)state;
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

int	ft_check_point_julia(t_state *state, double x, double y)
{
	int		iter;
	double	x_temp;
	double	r;
	double	r2;

	r = 7.5;
	r2 = sqrt(state->cx * state->cx + state->cy * state->cy) + r;
	iter = 1;
	while (x * x + y * y <= r2 && iter < 90)
	{
		x_temp = x * x - y * y;
		y = 2 * x * y + state->cy;
		x = x_temp + state->cx;
		iter += 1;
	}
	return (iter);
}

int	ft_check_point_tricorn(t_state *state, double x, double y)
{
	int		iter;
	double	x_temp;

	(void)state;
	iter = 1;
	while (x * x + y * y <= 4 && iter < 90)
	{
		x_temp = x * x - y * y + x;
		y = -2 * x * y + y;
		x = x_temp;
		iter += 1;
	}
	return (iter);
}

int	ft_check_point_ship(t_state *state, double x0, double y0)
{
	double	x;
	double	y;
	int		iter;
	double	x_temp;

	(void)state;
	x = 0;
	y = 0;
	iter = 0;
	while (x * x + y * y <= 2 * 2 && iter < 90)
	{
		x_temp = x * x - y * y + x0;
		y = fabs(2 * x * y) + y0;
		x = x_temp;
		iter += 1;
	}
	return (iter);
}

int	ft_check_point_baldelbrot(t_state *state, double x, double y)
{
	int		iter;
	double	magnitude;

	(void)state;
	iter = 0;
	magnitude = sqrt(x * x + y * y);
	while (magnitude < 1 && iter < 90)
	{
		if (x > 1)
			x = 2 - x;
		else if (x < -1)
			x = -2 - x;
		if (y > 1)
			y = 2 - y;
		else if (y < -1)
			y = -2 - y;
		magnitude = sqrt(x * x + y * y);
		x = state->scale * x + state->cx;
		y = state->scale * y + state->cy;
		iter += 1;
	}
	return (iter);
}
