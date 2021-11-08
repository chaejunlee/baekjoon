#include <bits/stdc++.h>
using namespace std;

int N = 0;
int land[100][100] = {{0}};
int cnt = 1000000;
int cntarr[100][100] = {{0}};
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int color = 2;
queue<pair<int, int>> q;

void printMatrix() {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << cntarr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << cnt << "\n";
}

void bfs(int x, int y, int color) {
    land[x][y] = color;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
                    if (land[dx][dy] == 1) {
                        land[dx][dy] = color;
                        q.push(make_pair(dx, dy));
                    }
                }
            }
        }
    }
}

void initIsland(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] == 1) {
                bfs(i, j, color);
                color++;
            }
        }
    }
}

void makeBridge(int n) {
    // // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         if (land[i][j] >= 2 && land[i][j] < color)
    //             for (int k = 0; k < 4; k++) {
    //                 int di = i + dir[k][0];
    //                 int dj = j + dir[k][1];
    //                 if (di >= 0 && di < n && dj >= 0 && dj < n) {
    //                     if (land[di][dj] == 0) {
    //                         land[di][dj] = land[i][j];
    //                         cntarr[di][dj] = 1;
    //                         q.push(make_pair(di, dj));
    //                     } else if (land[di][dj] != land[i][j]) {
    //                         cnt = 1;
    //                         return;
    //                     }
    //                     printMatrix();
    //                 }
    //             }
    //printMatrix();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j])
                q.push(make_pair(i, j));
        }
    }
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                    if (land[dx][dy] == 0) {
                        land[dx][dy] = land[x][y];
                        cntarr[dx][dy] = cntarr[x][y] + 1;
                        q.push(make_pair(dx, dy));
                    }
                    else if (land[dx][dy] != land[x][y]){
                        cnt = min(cnt, cntarr[dx][dy] + cntarr[x][y]);
                    }
                    //printMatrix();
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> land[i][j];

    initIsland(N);
    makeBridge(N);
    cout << cnt;
    return 0;
}