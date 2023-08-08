/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:35:35 by mucakmak          #+#    #+#             */
/*   Updated: 2023/07/29 17:48:52 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	int		byte;
	char	temp[BUFFER_SIZE + 1];

	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	byte = 1;
	while (!ft_check(str) && byte != 0)
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		temp[byte] = '\0';
		str = ft_strjoin(str, temp);
	}
	return (str);
}

char	*get_first_line(char *str)
{
	int		i;
	char	*line;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break ;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

char	*extract_line(char *str)
{
	int		len;
	int		starti;
	char	*lines;

	starti = -1;
	while (str[++starti])
		if (str[starti] == '\n')
			break ;
	if (str[starti] == '\n')
		starti++;
	len = ft_strlen(str) - starti + 1;
	lines = ft_substr(str, starti, len);
	free(str);
	return (lines);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0 || 0 >= BUFFER_SIZE)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd] || !*str[fd])
	{
		if (str[fd])
			free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	line = get_first_line(str[fd]);
	str[fd] = extract_line(str[fd]);
	return (line);
}
