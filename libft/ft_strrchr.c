/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:32:07 by mikabuto          #+#    #+#             */
/*   Updated: 2021/10/15 18:40:48 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (*s)
		s++;
	if (c == '\0')
		return ((char *)s);
	s--;
	while (len--)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
