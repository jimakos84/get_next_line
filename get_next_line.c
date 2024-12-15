/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:46:37 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/13 19:40:52 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	check_for_newline(char *buffer)
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
char	*leftovers_func(char *line)
{
	char	*leftovers;	
	int		mem_for_leftovers;
	int		clean_line_index;


	clean_line_index = check_for_newline(line);
	mem_for_leftovers = ft_strlen(line) - clean_line_index;
	leftovers = malloc(mem_for_leftovers + 1);
	leftovers = ft_strchr(line, '\n');
	return (leftovers);
}

char	*return_clean_newline(char *dirty_line)
{
	char	*clean_newline;
	int		clean_line_index;

	clean_line_index = check_for_newline(dirty_line);
	clean_newline = ft_substr(dirty_line, 0, clean_line_index);
	return (clean_newline);
}

char	*get_newline(int fd, char *left_overs)
{
	static char	*stash;
	char		*found_newline;
	int			bytesread;

	stash = malloc(BUFFER_SIZE + 1);
	if (stash == NULL)
		return (NULL);
	found_newline = ft_strdup(left_overs);
	bytesread = 1;
	while (1)
	{
		if (!check_for_newline(found_newline))
			bytesread = read(fd, stash, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(stash);
			return (NULL);
		}
		found_newline = ft_strjoin(found_newline, stash);
		if (check_for_newline(found_newline))
			break ;
	}
	free(stash);
	return (found_newline);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*clean_line;
	static char	*left_overs;
	
	if (left_overs == NULL)
		left_overs = ft_strdup("");
	line = get_newline(fd, left_overs);
	clean_line = return_clean_newline(line);
	left_overs = leftovers_func(line);
	return (clean_line);
}