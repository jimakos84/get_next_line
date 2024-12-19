/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:46:37 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/19 20:30:57 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	check_for_newline(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n' && i == 0)
			return (1);
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static char	*get_newline(int fd, char *left_overs)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*found_newline;
	char		*temp;
	int			bytesread;

	found_newline = ft_strdup(left_overs);
	if (!found_newline)
		return (NULL);
	bytesread = 1;
	while (!check_for_newline(found_newline) && bytesread > 0)
	{
		bytesread = read(fd, stash, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(found_newline);
			return (NULL);
		}
		stash[bytesread] = '\0';
		temp = ft_strjoin(found_newline, stash);
		free(found_newline);
		found_newline = temp;
		if (!found_newline)
			return (NULL);
	}
	return (found_newline);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*clean_line;
	static char	*left_overs;
	int			clean_line_index;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (left_overs)
		temp = left_overs;
	else
		temp = "";
	line = get_newline(fd, temp);
	if (!line)
	{
		free(left_overs);
		left_overs = NULL;
		return (NULL);
	}
	clean_line_index = check_for_newline(line) + 1;
	clean_line = ft_substr(line, 0, clean_line_index);
	free(left_overs);
	left_overs = ft_strdup(&line[clean_line_index]);
	free(line);
	return (clean_line);
}
