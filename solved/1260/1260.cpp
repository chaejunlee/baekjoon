#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;

int N = 0, M = 0, V = 0;
int adjacent[MAX][MAX] = {0};
bool visited[MAX] = {0};
queue<int> q;

void DFS(int from) {
    visited[from] = 1;
    cout << from << " ";
    for (int to = 1; to <= N; to++) {
        if (adjacent[from][to] && !visited[to]) {
            DFS(to);
        }
    }
}

void BFS(int from) {
    q.push(from);
    visited[from] = 1;

    while (!q.empty()) {
        from = q.front();
        q.pop();

        cout << from << " ";

        for (int to = 1; to <= N; to++) {
            if (adjacent[from][to] && !visited[to]) {
                visited[to] = 1;
                q.push(to);
            }
        }
    }
}

int main(void) {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin >> N >> M >> V;

    int from = 0, to = 0;

    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        adjacent[from][to] = 1;
        adjacent[to][from] = 1;
    }

    DFS(V);
    cout << "\n";
    for (int i = 0; i <= N; i++)
        visited[i] = 0;
    BFS(V);
    cout << "\n";

    return 0;
}