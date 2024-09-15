/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:15:45 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/29 19:11:00 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_error_gnl(char *str, char *str2);
char	*clean_stash(char *stash);
char	*extract_line(char *stash);
char	*add_to_stash(int fd, char *stash);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);

#endif
