/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:10:13 by ybesbes           #+#    #+#             */
/*   Updated: 2020/06/16 10:37:37 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

size_t  ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
char    *ft_strchr(const char *s, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif
