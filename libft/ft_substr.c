/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:07:10 by mikabuto          #+#    #+#             */
/*   Updated: 2021/11/08 17:25:50 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*case_start_bigger_s_len(void)
{
	char	*subs;

	subs = (char *)malloc(1);
	if (!subs)
		return (NULL);
	subs[0] = '\0';
	return (subs);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (case_start_bigger_s_len());
	if ((start + len) < s_len)
		subs = (char *)malloc(len + 1);
	else
		subs = (char *)malloc(s_len - start + 1);
	if (!subs)
		return (NULL);
	while (i < len && s[i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
