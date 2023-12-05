/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:14:07 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/05 19:47:01 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Documentation for MiniLibX:
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
https://gontjarow.github.io/MiniLibX/


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

				scroll up
				4
left click		middle click	right click
1				3				2
				scroll down
				5

*/

#include "ft_fractol.h"

void	custom_mlx_pixel_put(t_state *state, int x, int y, int color)
{
	char	*dst;

	dst = state->addr + (y * state->line_len + x * (state->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

void	ft_handle_argcargv(int argc, char *argv[], t_state *state)
{
	int	len;

	if (argc < 2)
		ft_wrong_args();
	state->type = argv[1];
	len = ft_strlen(argv[1]);
	if (!ft_strncmp(argv[1], "mandelbrot", len) && argc == 2)
		state->ft_check_point = ft_check_point_mandelbrot;
	else if (!ft_strncmp(argv[1], "julia", len) && argc == 4)
	{
		state->cx = ft_atod(argv[2]);
		state->cy = ft_atod(argv[3]);
		state->ft_check_point = ft_check_point_julia;
	}
	else if (!ft_strncmp(argv[1], "tricorn", len) && argc == 2)
		state->ft_check_point = ft_check_point_tricorn;
	else if (!ft_strncmp(argv[1], "ship", len) && argc == 2)
		state->ft_check_point = ft_check_point_ship;
	else if (!ft_strncmp(argv[1], "baldelbrot", len) && argc == 2)
		state->ft_check_point = ft_check_point_baldelbrot;
	else
		ft_wrong_args();
}

int	main(int argc, char *argv[])
{
	t_state	state;

	ft_handle_argcargv(argc, argv, &state);
	ft_instructions();
	ft_init_struct(&state);
	ft_init_mlx(&state);
	mlx_hook(state.win, 2, 1L << 0, ft_handle_control, &state);
	mlx_hook(state.win, 17, 0L, ft_handle_close, &state);
	mlx_mouse_hook(state.win, ft_handle_mouse, &state);
	mlx_loop_hook(state.mlx, render_next_frame, &state);
	mlx_loop(state.mlx);
	return (0);
}
