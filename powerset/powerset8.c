#include <stdlib.h>
#include <stdio.h>

void    powerset(int *a, int target, int n, int *sub, int size, int i, int sum)
{
    int j;

    if (sum == target)
    {
        j = 0;
        while (j < size) remember the loops
        {
            if (j)
                printf(" %d", sub[j]);
            else
                printf("%d", sub[j]);
            j++;
        }
        printf("\n");
    }

    while (i < n) //fix this one
    {
        sub[size] = a[i];
        powerset(a, target, n, sub, size + 1, i + 1, sum + a[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int target;
    int a[100];
    int sub[100];
    int n = argc - 2;
    int i = 0;

    if (argc < 3)
        return 1;

    target = atoi(argv[1]);

    while (i < n)
    {
        a[i] = atoi(argv[i + 2]);
        i++;
    }

    powerset(a, target, n, sub, 0, 0, 0);
    return 0;
}