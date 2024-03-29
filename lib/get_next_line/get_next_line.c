/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:41 by mzelouan          #+#    #+#             */
/*   Updated: 2024/01/21 05:23:56 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

void read_line_fd(char **stash, int fd)
{
    char *holder;
    int read_count;

    holder = NULL;
    while (!ft_strchr(*stash, '\n'))
    {
        holder = malloc(BUFFER_SIZE + 1);
        if (holder == NULL)
            return ;
        read_count = read(fd, holder, BUFFER_SIZE);
        if (read_count == 0)
        {
            free(holder);
            //free(*stash);
            return ;
        }
        if (read_count == -1)
        {
            free(holder);
            free(*stash);
            *stash = NULL;
            return ;
        }
        holder[read_count] = '\0';
        *stash = ft_strjoi(*stash, holder);
        free(holder);
    }
}

char *extract_line(char *stash)
{
    char *line;
    int i;

    line = NULL;
    i = 0;
    if (!stash  || !ft_strlen(stash))
		return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] && stash[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (line == NULL)
        return(NULL);
    i = -1;
    while (stash[++i] && stash[i] != '\n')
        line[i] = stash[i];
    if (stash[i] && stash[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return(line);
}

char *clean_stash(char *stash)
{
    char *holder;
    int i;
    int j;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] && stash[i] == '\n')
        i++;
    holder = malloc((ft_strlen(stash) - i) + 1);
    if (holder == NULL)
        return (NULL);
    while (stash[i])
    {
        holder[j] = stash[i];
        j++;
        i++;
    }
    holder[j] = '\0';
    free(stash);
    return (holder);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
        return (NULL);
    // 1 == read line from fd
    read_line_fd(&stash, fd);
    if (stash == NULL)
        return(NULL);
    // 2 == extract line
    line = extract_line(stash);
    // if (read(fd, line, 0) < 0)
    // {
    //     free(line);
    //     free(stash);
    //     return(NULL);
    // }
    // 3 == clean stash
    // if (line[0] == '\0')
    // {
    //     free(stash);
    //     free(line);
    //     return(NULL);
    // }
    if (line == NULL)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    stash = clean_stash(stash);
    return (line);
}