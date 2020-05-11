#include <bits/stdc++.h>
using namespace std;

int N = 0, M = 0;
int graph[1001][1001] = { 0 };
int visited[1001] = { 0 };

void DFS(int from) {
    visited[from] = 1;
    for (int to = 1; to <= M; to++)
        if (graph[from][to] && !visited[to])
            DFS(to);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int input = 0, cnt = 0;

    cin >> N;
    while (N--) {
        cin >> M;
        cnt = 0;
        for (int i = 1; i <= M; i++) {
            cin >> input;
            graph[i][input] = 1;
        }
        for (int i = 1; i <= M; i++) {
            if (!visited[i]) {
                DFS(i);
                cnt++;
            }
        }
        cout << cnt << "\n";
        fill(&graph[0][0], &graph[M][M], 0);
        fill_n(visited, M + 1, 0);
    }

    return 0;
}