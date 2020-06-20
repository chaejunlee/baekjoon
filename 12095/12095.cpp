#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n = 9;
int cnt = 0;

int queue[82][2] = {0};
int queue_size = 0;
int board[9][9] = {0};
int finished = 0;
int maxx = 0;

void sudoku(int i);
int promising(int ptr);

int square(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}
bool go(int z) {
    cnt += 1;
    if (cnt >= 100000) {
        return true;
    }
    int x = z / n;
    int y = z % n;
    if (a[x][y] != 0) {
        return go(z + 1);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
                a[x][y] = i;
                if (go(z + 1)) {
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
            }
        }
    }
    return false;
}

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
    if (promising(i)) {
        if (i == queue_size) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = board[i][j];
                    if (a[i][j] != 0) {
                        c[i][a[i][j]] = true;
                        c2[j][a[i][j]] = true;
                        c3[square(i, j)][a[i][j]] = true;
                    }
                }
            }
            cnt = 0;
            go(0);
            if (cnt == 100000)
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cout << board[i][j];
                    }
                    cout << "\n";
                }
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