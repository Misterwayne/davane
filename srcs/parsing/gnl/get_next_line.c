/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:11:15 by mwane             #+#    #+#             */
/*   Updated: 2019/11/02 18:22:16 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		scan_save(char *save)
{
	if (save)
		return (1);
	free(save);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	char static	*save;
	int			count;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))) || fd == -1)
		return (-1);
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		printf("buffer = %s\ncount = %d\n",buffer, count);
		save = reallocbuff(buffer, save);
		if (scan_buffer(save))
		{
			*line = giveline(save);
			save = setup_save(save);
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	if (count == -1)
		return (-1);
	*line = giveline(save);
	save = setup_save(save);
	return ((scan_save(save)) ? 1 : 0);
}

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = 0;
	//int i = 1;
	char	*line;
	int res = 1;
	
	line = NULL;
	fd = open("test.txt", O_RDONLY);
	while (res > 0)
	{
		res = get_next_line(0, &line);
		printf("ligne %d |%s|\n",res ,line);
		free(line);
	}
	close(fd);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);
	// printf("count = %d ligne %d = %s\n\n",get_next_line(fd, &line),i++,line);

	return 0;
}
