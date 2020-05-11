#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;

int graph[MAX][MAX] = {0};
int N = 0, M = 0, cnt = 0;
int connected[MAX] = {0}, visited[MAX] = {0};
queue<int> q;

void DFS(int from) {
    visited[from] = 1;
    for (int to = 1; to <= N; to++) {
        if (graph[from][to] && !visited[to]) {
            DFS(to);
        }
    }
}

void connectedComponent() {
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            DFS(i);
            cnt++;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int u = 0, v = 0;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    connectedComponent();

    cout << cnt;

    return 0;
}