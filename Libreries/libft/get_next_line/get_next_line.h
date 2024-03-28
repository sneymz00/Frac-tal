/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:26:42 by camurill          #+#    #+#             */
/*   Updated: 2024/03/26 18:17:34 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

char	*ft_get_line(char *text);
char	*ft_get_save(char *text, int *info);
char	*ft_get_text(int fd, char *text);
char	*get_next_line(int fd);
char	*ft_join_to_me(char *line, char *step, int len);
int		ft_len(char *str, char type);
int		ft_end_file(char *str);

#endif
