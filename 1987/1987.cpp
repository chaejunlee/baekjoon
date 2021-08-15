#include <bits/stdc++.h>
using namespace std;

int R, C;
char board[21][21];
int check[26] = {0};
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};


int solve(int y, int x) {
    int ret = 1;
    check[board[y][x] - 'A'] = 1;
    for (int i = 0; i < 4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (dy > 0 && dy <= R && dx > 0 && dx <= C) {
            int temp = 1;
            if (check[board[dy][dx] - 'A'] == 0) {
                temp = solve(dy, dx) + 1;
            }
            ret = max(ret, temp);
        }
    }
    check[board[y][x] - 'A'] = 0;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << solve(1, 1);
    
    return 0;
}
