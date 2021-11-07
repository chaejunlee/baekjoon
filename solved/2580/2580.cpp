#include <stdio.h>

int queue[82][2] = {0};
int queue_size = 0;
int board[9][9] = {0};
int finished = 0;

void sudoku(int i);
int promising(int ptr);

int main(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %d", &board[i][j]);
            if (!board[i][j]) {
                queue_size++;
                queue[queue_size][0] = i;
                queue[queue_size][1] = j;
            }
        }
    }
    sudoku(0);
    return 0;
}

void sudoku(int i) {
    if (promising(i) && !finished) {
        if (i == queue_size && !finished) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    printf("%d ", board[i][j]);
                }
                printf("\n");
            }
            finished = 1;
            return;
        } else {
            for (int j = 1; j <= 9; j++) {
                board[queue[i + 1][0]][queue[i + 1][1]] = j;
                sudoku(i + 1);
                board[queue[i + 1][0]][queue[i + 1][1]] = 0;
                // 모든 경우의 수를 시도했음에도 불구하고 실패했다면 했던 시도를 지워줘야한다.
            }
        }
    }
}

int promising(int ptr) {
    int r = queue[ptr][0];
    int c = queue[ptr][1];
    int part_r = r / 3;
    int part_c = c / 3;
    if (ptr) {
        for (int i = 0; i < 9; i++) {
            if (c != i)
                if (board[r][c] == board[r][i])
                    return 0;
        }
        for (int i = 0; i < 9; i++) {
            if (r != i)
                if (board[r][c] == board[i][c])
                    return 0;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (r != part_r * 3 + i && c != part_c * 3 + j)
                    if (board[r][c] == board[part_r * 3 + i][part_c * 3 + j])
                        return 0;
            }
        }
    }
    return 1;
}

/*
1 3 5 0 0 0 2 7 0 
0 8 2 1 3 5 0 4 9
4 0 9 2 7 8 1 0 5
3 2 1 5 4 6 8 9 7 
8 7 4 9 1 3 5 2 6
0 9 0 8 2 7 0 1 3
9 1 7 6 0 2 3 8 4
6 0 3 0 8 1 9 0 2 
2 5 8 3 9 0 7 6 0

1 3 5 4 6 9 2 7 8
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
8 7 4 9 1 3 5 2 6
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 3 8 4
6 4 3 7 8 1 9 5 2
2 5 8 3 9 4 7 6 1

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

0 0 0 0 0 8 0 6 3
8 0 3 0 0 0 0 0 0
0 0 4 0 0 6 5 8 0
4 3 0 7 0 2 0 0 0
0 0 6 0 1 0 0 2 7
0 0 2 6 8 0 0 4 0
3 4 0 8 6 7 9 5 2
9 8 7 0 0 0 6 3 4
6 2 0 0 9 0 7 1 0
41

3 0 4 0 0 0 6 0 0
7 0 2 6 4 5 1 0 0
1 0 0 0 3 8 0 0 4
4 0 0 0 0 6 0 9 0
5 7 0 0 0 1 3 2 0
6 2 8 0 0 0 7 0 1
0 4 0 3 0 0 0 1 0
8 0 0 0 6 4 0 3 2
9 3 0 8 0 2 4 0 5
41

9 0 0 0 0 0 0 0 0
0 1 8 0 0 0 0 0 0
0 5 0 0 0 4 0 0 6
3 0 0 0 0 0 0 0 4
0 0 0 1 9 0 0 0 0
0 0 7 0 0 0 0 0 0
0 0 0 0 0 0 0 9 5
0 0 0 0 0 0 1 8 0
0 0 2 0 0 6 0 0 0
64

9 0 0 0 0 0 3 0 0
0 0 1 0 7 0 0 0 0
0 0 0 0 5 0 0 6 8
4 0 0 0 0 0 0 0 0
0 0 0 6 0 5 0 0 0
7 0 2 0 0 0 0 0 0
0 5 0 3 0 0 0 0 0
0 0 0 0 0 0 0 7 2
0 0 0 0 0 0 0 0 9
64

5 0 0 0 7 0 9 0 2
0 9 2 0 4 8 0 0 0
0 0 0 0 0 0 4 0 6
0 0 8 1 9 0 7 0 0
0 0 3 5 0 0 0 2 0
6 0 0 4 0 0 0 0 8
9 0 0 0 0 0 0 0 0
0 4 0 0 0 0 0 0 0
7 0 0 0 3 5 0 1 0
55

0 0 0 1 0 0 2 5 0
7 0 3 5 9 0 0 1 0
0 0 6 0 0 0 0 0 0
5 0 9 0 0 8 0 4 0
6 4 0 2 0 0 0 0 7
0 0 0 0 0 0 0 0 6
0 0 0 0 0 3 0 2 0
0 1 0 7 0 0 4 0 0
0 0 0 0 8 6 7 0 0
55
*/