#include <stdio.h>

void solve(char *perm, int *used, char *str, int pos, int n)
{
    int i = 0;

    if (pos == n)
    {
        printf("%s\n", perm);
        return;
    }

    while (i < n)
    {
        if (!used[i])
        {
            used[i] = 1;
            perm[pos] = str[i];
            perm[pos + 1] = '\0';

            solve(perm, used, str, pos + 1, n);

            used[i] = 0;
        }
        i++;
    }
}

void sort(char *s)
{
    int i = 0;
    int j;
    char tmp;

    while (s[i])
    {
        j = i + 1;
        while (s[j])
        {
            if (s[i] > s[j])
            {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    char *str = argv[1];

    sort(str);

    int n = 0;
    while (str[n])
        n++;

    char perm[n + 1];
    int used[n];

    int i = 0;
    while (i < n)
    {
        used[i] = 0;
        i++;
    }

    solve(perm, used, str, 0, n);

    return 0;
}