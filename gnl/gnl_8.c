#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int  bytes = 0;
    static int  buffer_index = 0;
    char    *line = NULL;
    char    *temp;
    int line_len = 0;


    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    while (1)
    {
        if (buffer_index >= bytes)
        {
            bytes = read(fd, buffer, BUFFER_SIZE);
            if (bytes <= 0)
                break;
            buffer_index = 0;
        }
        temp = malloc(line_len + 2);
        if (!temp)
        {
            free(line);
            return NULL;
        }
        int i = 0;
        while (i < line_len)
        {
            temp[i] = line[i];
            i++;
        }
        temp[line_len] = buffer[buffer_index];
        temp[line_len + 1] = '\0';
        free (line);
        line = temp;
        line_len++;

        if (buffer[buffer_index] == '\n')
        {
            buffer_index++;
            return (line);
        }
        buffer_index++;

    }
    if (line_len == 0)
    {
        free (line);
        return NULL;
    }
    return (line);
}