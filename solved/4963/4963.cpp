#include <bits/stdc++.h>
using namespace std;

int land[50][50] = {0};
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int visited[50][50] = {0};
int cnt = 0;
int w = 0, h = 0;

void DFS(int x, int y) {
    visited[x][y] = 1;
    int dx, dy;
    for (int i = 0; i < 8; i++) {
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if ((dx >= 0 && dx < h) && (dy >= 0 && dy < w))
            if (land[dx][dy] && !visited[dx][dy])
                DFS(dx, dy);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
    while (w + h) {
        cnt = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> land[i][j];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (land[i][j] && !visited[i][j]) {
                    DFS(i, j);
                    cnt++;
                }
        cout << cnt << "\n";
        fill(&land[0][0], &land[0][0] + 2500, 0);
        fill(&visited[0][0], &visited[0][0] + 2500, 0);
        cin >> w >> h;
    }

    return 0;
}