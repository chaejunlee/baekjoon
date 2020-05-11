#include <bits/stdc++.h>
using namespace std;

int maze[100][100] = {{0}};
int visited[100][100] = {{0}};
int N = 0, M = 0;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
queue<pair<int, int>> q;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
            maze[i][j] = s[j] - '0';
    }

    int x = 0, y = 0;
    int dx = 0, dy = 0;
    int cnt = 0;
    q.push(make_pair(x, y));
    visited[0][0] = 1;
    while (!q.empty()) {
        cnt++;
        int qsize = q.size();
        while (qsize--) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if (x == N - 1 && y == M - 1) {
                while (!q.empty()) {
                    q.pop();
                }
                break;
            }
            for (int i = 0; i < 4; i++) {
                dx = x + dir[i][0];
                dy = y + dir[i][1];
                if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
                    if (maze[dx][dy] && !visited[dx][dy]) {
                        visited[dx][dy] = 1;
                        q.push(make_pair(dx, dy));
                    }
                }
            }
            // cout << "\n";
            // for (int i = 0; i < N; i++) {
            //     for (int j = 0; j < M; j++) {
            //         cout << visited[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "cnt: " << cnt << "\n";
        }
    }
    cout << cnt;
    return 0;
}