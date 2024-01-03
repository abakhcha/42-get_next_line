/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:53:07 by abakhcha          #+#    #+#             */
/*   Updated: 2024/01/03 12:51:25 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*rdsv(int fd, char *str)
{
	int		reader;
	char	*buff;

	reader = 1;
	if (!str)
		str = ft_calloc(1, 1);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!check_newline(str) && reader != 0)
	{
		reader = (int)read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[reader] = '\0';
		str = str_join(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_l(char *str)
{
	int		i;
	char	*rts;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	rts = malloc(i + 2);
	if (!rts)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rts[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		rts[i++] = '\n';
	rts[i] = '\0';
	return (rts);
}

char	*get_next_line(int fd)
{
	static char	*line[10240];
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = rdsv(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	buff = get_l(line[fd]);
	line[fd] = save(line[fd]);
	return (buff);
}
