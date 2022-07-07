/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:53:24 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/07 15:58:07 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_fractol *f)
{
	int			x;
	int			y;
	int			i;

	mlx_clear_window(f->mlx, f->window);
	y = -1;
	while (++y < HEI)
	{
		f->c.im = (f->dy - y) * f->factor.im;
		x = -1;
		while (++x < WID)
		{
			f->c.re = (x - f->dx) * f->factor.re;
			i = f->formula(f, x, y);
			put_color(f->image, i, x, y);
		}
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image->image, 0, 0);
}

void	create_image(t_fractol *frac)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->image = mlx_new_image(frac->mlx, WID, HEI);
	img->data_addr = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
	&img->size_line, &img->endian);
	frac->image = img;
	init_factor(frac);
	draw_fractol(frac);
	hooks(frac);
}

int	main(int argc, char **argv)
{
	t_fractol	frac;

	if (argc == 2 && arg_handle(argv[1], &frac))
	{
		frac.mlx = mlx_init();
		frac.window = mlx_new_window(frac.mlx, WID, HEI, "fractol");
		create_image(&frac);
		mlx_loop(frac.mlx);
	}
	else
	{
		ft_putstr("Args must be:\nMandelbrot\nJulia || Julia1 || Julia2\n");
		ft_putstr("Celtic_mandelbrot\nBurning_ship\n");
	}
	return (0);
}
