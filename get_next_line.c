/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 23:02:45 by afaraji           #+#    #+#             */
/*   Updated: 2018/12/13 18:40:15 by afaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*oldline[590432];
	int			i;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!oldline[fd])
		oldline[fd] = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		oldline[fd] = ft_strjoin(oldline[fd], buff);
		if (ft_strchr(oldline[fd], '\n'))
			break ;
	}
	i = 0;
	while (oldline[fd][i] != '\n' && oldline[fd][i] != '\0')
		i++;
	*line = ft_strsub(oldline[fd], 0, i);
	if (!ft_strlen(oldline[fd]) && !ret && !i)
		return (0);
	oldline[fd] = ft_strdup(oldline[fd] + i + 1);
	return (1);
}
