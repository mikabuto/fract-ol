/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:07:44 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/08 17:06:00 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	put_color(t_fractol *f, int i, int x, int y)
{
	double	t;
	int		color;

	if (i == ITER)
		ft_mlx_pixel_put(f->image, x, y, create_rgb(0, 0, 0));
	else
	{
		t = (double)i / ITER;
		color = create_rgb((int)(9 * (1 - t) * pow(t, 3) * 255), \
							(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255), \
							(int)(8.5 * pow((1 - t), 3) * t * 255));
		if (f->color_shift == 1)
			color = create_rgb((int)(15 * pow((1 - t), 2) * pow(t, 2) * 255), \
							(int)(8.5 * pow((1 - t), 3) * t * 255), \
							(int)(9 * (1 - t) * pow(t, 3) * 255));
		else if (f->color_shift == 2)
			color = create_rgb((int)(8.5 * pow((1 - t), 3) * t * 255), \
							(int)(9 * (1 - t) * pow(t, 3) * 255), \
							(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255));
		ft_mlx_pixel_put(f->image, x, y, color);
	}
}
