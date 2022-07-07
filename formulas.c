/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:24:34 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/07 14:41:35 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *f, int x, int y)
{
	int			i;
	t_complex	z;

	i = 0;
	f->c.im = (f->dy - y) * f->factor.im;
	f->c.re = (x - f->dx) * f->factor.re;
	z = init_complex(f->c.re, f->c.im);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 && i < ITER)
	{
		z = init_complex(pow(z.re, 2) - pow(z.im, 2) + f->c.re, \
				2 * z.re * z.im + f->c.im);
		i++;
	}
	return (i);
}

int	julia(t_fractol *f, int x, int y)
{
	int			i;
	t_complex	z;

	i = 0;
	z = init_complex((f->dy - y) * f->factor.im, (x - f->dx) * f->factor.re);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 && i < ITER)
	{
		z = init_complex(pow(z.re, 2) - pow(z.im, 2) + f->julia_c.re, \
				2 * z.re * z.im + f->julia_c.im);
		i++;
	}
	return (i);
}

int	celtic(t_fractol *f, int x, int y)
{
	int			i;
	t_complex	z;

	i = 0;
	f->c.im = (f->dy - y) * f->factor.im;
	f->c.re = (x - f->dx) * f->factor.re;
	z = init_complex(f->c.re, f->c.im);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 && i < ITER)
	{
		z = init_complex(fabs(pow(z.re, 2) - pow(z.im, 2)) + f->c.re, \
				2 * z.re * z.im + f->c.im);
		i++;
	}
	return (i);
}

int	ship(t_fractol *f, int x, int y)
{
	int			i;
	t_complex	z;

	i = 0;
	f->c.im = (f->dy - y) * f->factor.im;
	f->c.re = (x - f->dx) * f->factor.re;
	z = init_complex(f->c.re, f->c.im);
	while (pow(z.re, 2) + pow(z.im, 2) <= 4 && i < ITER)
	{
		z = init_complex(pow(z.re, 2) - pow(z.im, 2) + f->c.re, \
				-2 * fabs(z.re * z.im) + f->c.im);
		i++;
	}
	return (i);
}

int	arg_handle(char *arg, t_fractol *f)
{
	if (!ft_strcmp(arg, "Mandelbrot"))
		f->formula = &mandelbrot;
	else if (!ft_strcmp(arg, "Celtic_mandelbrot"))
		f->formula = &celtic;
	else if (!ft_strcmp(arg, "Burning_ship"))
		f->formula = &ship;
	else if (!ft_strcmp(arg, "Julia"))
	{
		f->formula = &julia;
		f->julia_c = init_complex(-0.4, 0.6);
	}
	else if (!ft_strcmp(arg, "Julia1"))
	{
		f->formula = &julia;
		f->julia_c = init_complex(-0.98, -0.894);
	}
	else if (!ft_strcmp(arg, "Julia2"))
	{
		f->formula = &julia;
		f->julia_c = init_complex(0.4, -0.3);
	}
	else
		return (0);
	return (1);
}
