/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:13:26 by jaehjoo           #+#    #+#             */
/*   Updated: 2022/07/15 10:41:04 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		idx;
	int		len;

	idx = 0;
	len = 0;
	while (s1[len])
		len++;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}

char	*ft_getstrchr(const char *str, int c)
{
	size_t			idx;
	unsigned char	tgt;

	idx = 0;
	tgt = (unsigned char)c;
	if (!str)
		return (0);
	while (str[idx])
	{
		if (str[idx] == tgt)
			return ((char *)str + idx);
		idx++;
	}
	if (str[idx] == tgt)
		return ((char *)str + idx);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(s1_len + s2_len + 1);
	if (!temp)
		return (0);
	s1_len = 0;
	while (s1[s1_len])
	{
		temp[s1_len] = s1[s1_len];
		s1_len++;
	}
	s2_len = 0;
	while (s2[s2_len])
	{
		temp[s1_len + s2_len] = s2[s2_len];
		s2_len++;
	}
	temp[s1_len + s2_len] = 0;
	return (temp);
}
