/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:51:58 by mikabuto          #+#    #+#             */
/*   Updated: 2021/10/20 20:39:42 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_ft_power(int a)
{
	int	n;

	n = 1;
	while (a--)
		n *= 10;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		i;

	i = -1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	len = ft_ft_num_len(n);
	while (++i < len)
	{
		ft_putchar_fd((n / ft_ft_power(len - i - 1) % 10) + '0', fd);
	}
}
