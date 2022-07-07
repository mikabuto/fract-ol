/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:48:24 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/07 15:48:59 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keycode.h"

int	fractol_exit(t_fractol *f)
{
	if (f->mlx && f->window)
		mlx_destroy_window(f->mlx, f->window);
	if (f->mlx && f->image->image)
		mlx_destroy_image(f->mlx, f->image->image);
	exit(0);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == ESC_KEY)
		fractol_exit(f);
	if (keycode == UP_KEY)
		f->dy += 10;
	if (keycode == DOWN_KEY)
		f->dy -= 10;
	if (keycode == RIGHT_KEY)
		f->dx -= 10;
	if (keycode == LEFT_KEY)
		f->dx += 10;
	draw_fractol(f);
	return (0);
}

int	scroll_hook(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == SCROLLDOWN_KEY)
	{
		f->factor.re *= 1.1;
		f->factor.im *= 1.1;
		f->dx += (WID / 2 - x) / 2;
		f->dy += (HEI / 2 - y) / 2;
	}
	else if (keycode == SCROLLUP_KEY)
	{
		f->factor.re *= 0.9;
		f->factor.im *= 0.9;
		f->dx += (WID / 2 - x) / 2;
		f->dy += (HEI / 2 - y) / 2;
	}
	draw_fractol(f);
	return (0);
}

void	hooks(t_fractol *f)
{
	mlx_hook(f->window, KEYPRESS, 0, key_hook, f);
	mlx_hook(f->window, BUTTONPRESS, 0, scroll_hook, f);
	mlx_hook(f->window, DESTROYNOTIFY, 0, fractol_exit, f);
}
