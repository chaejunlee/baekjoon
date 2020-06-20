#include <stdio.h>

char input[9] = "";
int queue[82][2] = {0};
int queue_size = 0;
int board[9][9] = {0};
int finished = 0;

void sudoku(int i);
int promising(int ptr);

int main(void) {
    for (int i = 0; i < 9; i++) {
        scanf(" %s", &input);
        for (int j = 0; j < 9; j++) {
            board[i][j] = input[j] - '0';
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
                    printf("%d", board[i][j]);
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