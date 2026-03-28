#include <stdio.h>
#include <stdlib.h>

void    powerset(int *a, int n, int target, int *sub, int size, int i, int sum)
{
    int j;

    if (sum == target)
    {
        j = 0;
        while (j < size)
        {
            if (j)
                printf(" %d", sub[j]);
            else
                printf("%d", sub[j]);
            j++;
        }
        printf("\n");
    }
    while (i < n)
    {
        sub[size] = a[i];
        powerset(a, n, target, sub, size + 1, i + 1, sum + a[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int target;
    int n = argc - 2;
    int a[100];
    int sub[100];
    int i = 0;

    if (argc < 3)
        return 1;
        
    target = atoi(argv[1]);

    while (i < n)
    {
        a[i] = atoi(argv[i + 2]);
        i++;
    }
    powerset(a, n, target, sub, 0, 0, 0);
    return (0);
}
