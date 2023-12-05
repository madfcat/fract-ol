/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:31:51 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/05 20:35:04 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_init_struct(t_state	*state)
{
	state->width = 400;
	state->height = 400;
	state->zoom = 1;
	state->mouse_x = 0;
	state->mouse_y = 0;
	state->left = -2.00;
	state->right = 2.00;
	state->top = 2.00;
	state->bottom = -2.00;
	state->zoom_count = 0;
	state->prev_x_step = 0;
	state->prev_y_step = 0;
	state->color1 = 0x0000270F;
	state->color2 = 0x00000000;
	state->frame = 0;
	state->pause = 1;
	state->scale = 3;
}

void	ft_init_mlx(t_state *state)
{
	state->mlx = mlx_init();
	if (!state->mlx)
		exit(0);
	state->win = mlx_new_window(state->mlx, state->width,
			state->height, "Fract-ol");
	if (!state->win)
	{
		free(state->mlx);
		exit(0);
	}
	state->img = mlx_new_image(state->mlx, state->width, state->height);
	if (!state->img)
	{
		free(state->mlx);
		free(state->win);
		exit(0);
	}
	state->addr = mlx_get_data_addr(state->img,
			&state->bits_per_pixel, &state->line_len, &state->endian);
}
