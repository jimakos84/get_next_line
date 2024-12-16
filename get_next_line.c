/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:46:37 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/16 18:43:43 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	check_for_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static char *get_newline(int fd, char *left_overs)
{
	static char stash[BUFFER_SIZE + 1];
	char *found_newline;
	char *temp;
	int bytesread;

	found_newline = ft_strdup(left_overs);  // Create a copy
	if (!found_newline)
		return (NULL);
	bytesread = 1;
	while (!check_for_newline(found_newline) && bytesread > 0)
	{
		bytesread = read(fd, stash, BUFFER_SIZE);
	if (bytesread <= 0)
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

char *get_next_line(int fd)
{
	char *line;
	char *clean_line;
	static char *left_overs;
	int clean_line_index;
	char  *temp;

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
	clean_line_index = check_for_newline(line);
	clean_line = ft_substr(line, 0, clean_line_index + 1);
	free(left_overs); 
	left_overs = ft_strdup(&line[clean_line_index + 1]);
	free(line); 
	return (clean_line);
}
