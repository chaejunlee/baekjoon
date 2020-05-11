#include <bits/stdc++.h>
using namespace std;

int N = 0, cnt;
int graph[25][25] = {0};
int visited[25][25] = {0};
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<int> v;

void DFS(int x, int y) {
    visited[x][y] = v.size() + 1;
    int nextX = x, nextY = y;
    for (int i = 0; i < 4; i++) {
        nextX = x + dir[i][0];
        nextY = y + dir[i][1];
        if ((nextX >= 0 && nextX < 25) && (nextY >= 0 && nextY < 25))
            if (graph[nextX][nextY] && !visited[nextX][nextY]) {
                DFS(nextX, nextY);
                cnt++;
            }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            graph[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((!visited[i][j]) && graph[i][j]) {
                cnt = 1;
                DFS(i, j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size()  << "\n";
    for (int i : v) {
        cout << i << "\n";
    }

    return 0;
}