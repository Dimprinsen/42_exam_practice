#include <stdio.h>
#include <stdlib.h>

void    powerset(int *a, int n, int target, int *sub, int size, int i, int sum)
{
    int j;

    if (sum == target)
    {
        j = 0;
        while (j < size) //should be less than size, not n
        {
            if (j)
                printf(" %d", sub[j]); //first should have space
            else
                printf("%d", sub[j]); //second should not have space
            j++;
        }
        printf("\n");
    }
    while (i < n)
    {
        sub[size] = a[i]; //should be sub[size];
        powerset(a, n, target, sub, size + 1, i + 1, sum + a[i]);//forgot recursion, lmao
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
        a[i] = atoi(argv[i + 2]); //forgot atoi
        i++;
    }
    powerset(a, n, target, sub, 0, 0, 0);
    return 0;
}