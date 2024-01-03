/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:53:24 by abakhcha          #+#    #+#             */
/*   Updated: 2024/01/03 13:37:40 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save(char *str)
{
	int		i;
	int		j;
	char	*rts;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rts = malloc(ft_strlen(str) - i + 1);
	if (!rts)
		return (NULL);
	i++;
	j = 0;
	while (i[str])
		rts[j++] = str[i++];
	rts[j] = '\0';
	free(str);
	return (rts);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*str_join(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free((char *)s1);
	return (str);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t s, size_t size)
{
	unsigned char	*ss;
	size_t			i;
	void			*ptr;

	i = 0;
	if (size && s * size > (size_t)-1)
		return (NULL);
	ptr = (void *)malloc(s * size);
	ss = (unsigned char *)ptr;
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ss[i] = 0;
		i++;
	}
	return (ss);
}
