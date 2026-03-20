#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void    ft_filter(char *buffer, const char *target)
{
    int i = 0;
    int target_len = strlen(target);
    int j, k;

    while (buffer[i])
    {
        j = 0;
        while (target[j] && buffer[i + j] == target[j])
            j++;
        if (j == target_len)
        {
            k = 0;
            while (k < target_len)
            {
                write(1, "*", 1);
                k++;
            }
            i += target_len;
        }
        else
        {
            write(1, &buffer[i], 1);
            i++;
        }
    }
}

int main(int argc, char *argv[])
{
    char    *temp[BUFFER_SIZE];
    char    *result = NULL;
    char    *buffer;
    ssize_t bytes;
    int total_read = 0;

    if (argc != 2 || argv[1][0] == '\0')
        return 1;

    while ((bytes = read(0, temp, BUFFER_SIZE)) > 0)
    {
        buffer = realloc(result, total_read + bytes + 1);
        if (!buffer)
        {
            perror("realloc");
            free (result);
            return 1;
        }
        result = buffer;

        memmove(result + total_read, temp, bytes);
        total_read += bytes;
        result[total_read] = '\0';
    }
    if (bytes < 0)
    {
        perror ("read");
        free (result);
        return 1;
    }
    if (!result)
        return 0;
    ft_filter(result, argv[1]);
    free (result);
    return 0;
}