/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:44:36 by camurill          #+#    #+#             */
/*   Updated: 2024/03/14 13:52:20 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *str, char type)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != type)
		i++;
	return (i);
}

char	*ft_join_to_me(char *line, char *step, int len)
{
	char	*alpha;
	int		i;
	int		j;
	int		size;

	size = ft_len(line, '\0');
	alpha = malloc(sizeof(char) * (size + len + 1));
	if (!alpha)
		return (free(line), NULL);
	i = 0;
	while (i < size)
	{
		alpha[i] = line[i];
		i++;
	}
	j = 0;
	while (i < size + len)
		alpha[i++] = step[j++];
	alpha[i] = '\0';
	free(line);
	return (alpha);
}

int	ft_end_file(char *str)
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
