/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:46:50 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/05 20:30:44 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_print_stats(t_state	*state)
{
	char	*output;
	char	*temp;

	output = ft_strjoin("Type: ", state->type);
	mlx_string_put(state->mlx, state->win, 20, 30, 0xFFFFFF, output);
	free(output);
	temp = ft_itoa(state->zoom_count);
	output = ft_strjoin("Zoom: ", temp);
	mlx_string_put(state->mlx, state->win, 20, 50, 0xFFFFFF, output);
	free(output);
	free(temp);
}

void	ft_wrong_args(void)
{
	ft_putstr_fd("Amount of arguments is wrong.\n", 1);
	ft_putstr_fd("Syntax: ./fractol <mandelbrot | ", 1);
	ft_putstr_fd("julia <x> <y> | tricorn | ship | ", 1);
	ft_putstr_fd("baldelbrot> <max_iteration>\n", 1);
	ft_putstr_fd("For example: ./fractol julia -0.135 -0.721 90\n", 1);
	exit(0);
}

void	ft_instructions(void)
{
	ft_putstr_fd("Controls:\n\nPan with arrows\n", 1);
	ft_putstr_fd("Zoom with scroll\nClick to center\n", 1);
	ft_putstr_fd("Press C to switch base color shift on/off\n", 1);
	ft_putstr_fd("Press X or V to decrement/increment the base color\n", 1);
	ft_putstr_fd("Press - or + and [ or ] to modify Julia and Baldelbrot\n", 1);
	ft_putstr_fd("Press A or S  to scale Baldelbrot\n\n", 1);
	ft_putstr_fd("Press 1 for Julia set\n", 1);
	ft_putstr_fd("Press 2 for Mandelbrot set\n", 1);
	ft_putstr_fd("Press 3 for Tricorn (Mandelbar set)\n", 1);
	ft_putstr_fd("Press 4 for Burning ship\n", 1);
	ft_putstr_fd("Press 5 for Baldelbrot (Custom fractal discovered in ", 1);
	ft_putstr_fd("search of Mandelbox)\n\n", 1);
}
