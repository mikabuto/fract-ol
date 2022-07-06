/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 03:00:22 by mikabuto          #+#    #+#             */
/*   Updated: 2021/11/08 17:20:31 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_len(int n)
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

int	ft_power(int a)
{
	int	n;

	n = 1;
	while (a--)
		n *= 10;
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*ret;

	len = ft_num_len(n);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = -1;
	if (n < 0)
		i = 0;
	while (++i < len)
	{
		if (n < 0)
		{
			ret[0] = '-';
			ret[i] = -(n / ft_power(len - i - 1) % 10) + '0';
		}
		else
			ret[i] = (n / ft_power(len - i - 1) % 10) + '0';
	}
	ret[i] = '\0';
	return (ret);
}
