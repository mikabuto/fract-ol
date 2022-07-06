/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:53:24 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/06 20:03:23 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *f, t_image *img)
{
	int			x;
	int			y;
	int			i;
	t_complex	z;

	y = -1;
	while (++y < HEI)
	{
		// f->c.im = f->max.im - y * f->factor.im;
		x = -1;
		while (++x < WID)
		{
			// f->c.re = f->min.re + x * f->factor.re;
			f->c.re = (x - f->dx) * f->factor.re;
			f->c.im = (f->dy - y) * f->factor.im;
			z = init_complex(f->c.re, f->c.im);
			i = 0;
			// // printf("c = %f %f z = %f %f\n", f->c.re, f->c.im, z.re, z.im);
			while (pow(z.re, 2) + pow(z.im, 2) <= 4 && i < ITER)
			{
				z = init_complex(pow(z.re, 2) - pow(z.im, 2) + f->c.re, \
						2 * z.re * z.im + f->c.im);
				i++;
			}
			put_color(img, i, x, y);
		}
	}
}

void	create_image(t_fractol *frac)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->image = mlx_new_image(frac->mlx, WID, HEI);
	img->data_addr = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
	&img->size_line, &img->endian);
	init_factor(frac);
	mandelbrot(frac, img);
	mlx_put_image_to_window(frac->mlx, frac->window, img->image, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	*frac;

	frac = malloc(sizeof(t_fractol));
	if (argc != 2 || !frac)
		return (0);
	if (!ft_strncmp(argv[1], "Mandelbrot", 12))
	{
		frac->mlx = mlx_init();
		frac->window = mlx_new_window(frac->mlx, WID, HEI, "fractol");
		create_image(frac);
		mlx_loop(frac->mlx);
	}
	return (0);
}
