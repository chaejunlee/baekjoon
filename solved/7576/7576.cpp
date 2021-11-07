#include <bits/stdc++.h>
using namespace std;

int m = 0, n = 0;
int box[1000][1000] = {{0}};
int visited[1000][1000] = {{0}};
int spread[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int cnt = -1;
queue<pair<int, int>> q;

void tomato(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (box[i][j] == 1 && !visited[i][j]) {
                q.push(make_pair(i, j));
            }
        }
    }
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            int r, c;
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int dr = r + spread[j][0];
                int dc = c + spread[j][1];
                if (dr >= 0 && dr < m && dc >= 0 && dc < n)
                    if (box[dr][dc] == 0) {
                        box[dr][dc] = 1;
                        q.push(make_pair(dr, dc));
                    }
            }
        }
        cnt++;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << box[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (box[i][j] == 0) {
                cnt = -1;
                return;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> box[i][j];
        }
    }

    tomato(m, n);
    cout << cnt;

    return 0;
}