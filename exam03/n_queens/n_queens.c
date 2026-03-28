#include <stdlib.h>
#include <stdio.h>

int is_safe(int *board, int col, int row)
{
    int i = 0;
    while (i < col)
    {
        if (board[i] == row ||
            board[i] - row == i - col ||
            board[i] - row == col - i)
            return 0;
        i++;
    }
    return 1;
}

void    solve(int *board, int col, int n)
{
    if (col == n)
    {
        int i = 0;
        while (i < n)
        {
            printf("%d", board[i]);
            if (i < n - 1)
                printf(" ");
            i++;
        }
        printf("\n");
        return ;
    }
    int row = 0;
    while (row < n)
    {
        if (is_safe(board, col, row))
        {
            board[col] = row;
            solve(board, col + 1, n);
        }
        row++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

     int n = atoi(argv[1]);
     if (n <= 0)
        return 1;

    int *board = calloc(n, sizeof(int));
    if (!board)
        return 1;

    solve(board, 0, n);
    free(board);
    return 0;
}