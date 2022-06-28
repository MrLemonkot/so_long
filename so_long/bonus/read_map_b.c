/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:50:52 by akayle            #+#    #+#             */
/*   Updated: 2022/06/27 19:51:16 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	count_lines(char *filename)
{
	int		lines_num;
	int		fd;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	lines_num = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp)
		{
			if (tmp[0] == '\n')
			{
				free(tmp);
				error("Map has zero lines.");
			}
			lines_num++;
		}
		else
			break ;
		free(tmp);
	}
	close(fd);
	return (lines_num);
}

char	*file_to_array(char *filename)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*new_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("File is not readable.");
	line = ft_strdup("");
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		temp = line;
		line = ft_strjoin(line, new_line);
		free(temp);
		free(new_line);
	}
	close(fd);
	return (line);
}
