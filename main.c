/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:14:07 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/05 20:31:55 by vshchuki         ###   ########.fr       */
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

void	ft_handle_argc_2_3(int argc, char *argv[], t_state *state, int len)
{
	state->max_iter = 90;
	if (!ft_strncmp(argv[1], "mandelbrot", len))
		state->ft_check_point = ft_check_point_mandelbrot;
	else if (!ft_strncmp(argv[1], "tricorn", len))
		state->ft_check_point = ft_check_point_tricorn;
	else if (!ft_strncmp(argv[1], "ship", len))
		state->ft_check_point = ft_check_point_ship;
	else if (!ft_strncmp(argv[1], "baldelbrot", len))
		state->ft_check_point = ft_check_point_baldelbrot;
	else
		ft_wrong_args();
	if (argc == 3)
	{
		state->max_iter = ft_atoi(argv[2]);
		if (state->max_iter == 0)
			ft_wrong_args();
	}
}

void	ft_handle_argcargv(int argc, char *argv[], t_state *state)
{
	int	len;

	if (argc < 2)
		ft_wrong_args();
	state->type = argv[1];
	len = ft_strlen(argv[1]);
	if (argc == 2 || argc == 3)
		ft_handle_argc_2_3(argc, argv, state, len);
	else if (!ft_strncmp(argv[1], "julia", len) && (argc == 4 || argc == 5))
	{
		state->cx = ft_atod(argv[2]);
		state->cy = ft_atod(argv[3]);
		state->ft_check_point = ft_check_point_julia;
		if (argc == 5)
		{
			state->max_iter = ft_atoi(argv[4]);
			if (state->max_iter == 0)
				ft_wrong_args();
		}
	}
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
