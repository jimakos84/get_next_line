/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:22:23 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/13 19:40:14 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int     main(void)
{
	int	i = 5;
	int     fd;
	fd = open("bangers.txt", O_RDWR);
	while (i--)
		printf("%s", get_next_line(fd));

	return (0);
}
