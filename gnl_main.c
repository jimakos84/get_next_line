/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:22:23 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/16 15:04:42 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int     main(void)
{
	int	i;
	int     fd;
		
	i = 11;
	fd = open("bangers.txt", O_RDONLY);
	while (i--)
		printf("%s", get_next_line(fd));
	close(fd);		
	return (0);
}
