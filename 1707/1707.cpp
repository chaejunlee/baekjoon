#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 20000 + 1
#define RED 1
#define BLUE 2

using namespace std;

int K, V, E;
vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];

void bfs(int start);
bool isBipartiteGraph();

void bfs(int start) {
    queue<int> q;
    int color = RED;

    visited[start] = color;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (visited[now] == RED) {
            color = BLUE;
        }
        else if (visited[now] == BLUE) {
            color = RED;
        }

        int gsize = graph[now].size();
        for (int i = 0; i < gsize; i++) {
            int next = graph[now][i];
            if (!visited[next]) {
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

bool isBarpartiteGraph() {
    for (int i = 1; i <= V; i++) {
        int gsize = graph[i].size();
        for (int j = 0; j < gsize; j++) {
            int next = graph[i][j];
            if (visited[i] == visited[next]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    while (K--) {
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            int u = 0, v = 0;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                bfs(i);
            }
        }

        cout << (isBarpartiteGraph() ? "YES" : "NO") << "\n";

        for (int i = 0; i <= V; i++) 
            graph[i].clear();
        fill_n(visited, V + 1, false);
    }
}