/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:36:56 by jaehjoo           #+#    #+#             */
/*   Updated: 2022/07/15 17:49:25 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strfree(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		str[idx] = 0;
	free(str);
}

static char	*ft_read_file(int fd, char *backup)
{
	int		flag;
	char	*temp_cpy;
	char	buf[BUFFER_SIZE + 1];

	while (!ft_getstrchr(backup, '\n'))
	{
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag == -1)
			return (0);
		else if (!flag)
			break ;
		if (!backup)
			backup = ft_strdup("");
		buf[flag] = 0;
		temp_cpy = backup;
		backup = ft_strjoin(temp_cpy, buf);
		ft_strfree(temp_cpy);
		if (!backup)
			return (0);
	}
	return (backup);
}

static char	*ft_get_line(char *ln)
{
	int		idx;

	idx = 0;
	while (ln[idx] && ln[idx] != '\n')
		idx++;
	if (ln[idx] == '\n')
		ln[idx] = 0;
	return (ln);
}

static char	*ft_sep_line(char *ln)
{
	int		idx;
	char	*res;

	idx = 0;
	while (ln[idx] && ln[idx] != '\n')
		idx++;
	if (!ln[idx])
		return (0);
	res = ft_strdup(ln + idx + 1);
	if (!res)
		return (0);
	if (!res[0])
	{
		ft_strfree(res);
		return (0);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*ln;

	if (fd < 0)
		return (0);
	ln = ft_read_file(fd, backup);
	if (!ln)
		return (0);
	backup = ft_sep_line(ln);
	ln = ft_get_line(ln);
	return (ln);
}
