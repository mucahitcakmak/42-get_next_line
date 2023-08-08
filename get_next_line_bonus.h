/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:37:11 by mucakmak          #+#    #+#             */
/*   Updated: 2023/07/29 19:00:20 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// get_next_line_bonus.c
char	*ft_read(int fd, char *str);
char	*get_first_line(char *str);
char	*extract_line(char *str);
char	*get_next_line(int fd);

// get_next_line_utils_bonus.c
int		ft_strlen(char *str);
int		ft_check(char *str);
char	*ft_substr(char *str, int start, int len);
char	*ft_strjoin(char *s1, char *s2);

#endif