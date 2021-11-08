#include <bits/stdc++.h>
using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int dist[20001] = {0};
int visited[20001] = {0};
const int MAX = INT_MAX;

int findShortestNode() {
    int minDist, minIndex;
    minDist = MAX;
    minIndex = -1;
    for (int i = 1; i <= V; i++) {
        if (visited[i]) continue;
        if (dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void updateDist(int newNode) {
    for (auto v : graph[newNode]) {
        if (visited[v.first]) continue;
        if (dist[v.first] > dist[newNode] + v.second) {
            dist[v.first] = dist[newNode] + v.second;
        }
    }
}

void solve() {
    for (int i = 1; i <= V; i++) {
        dist[i] = MAX;
    }
    for (auto i : graph[K]) {
        dist[i.first] = i.second;
    }
    dist[K] = 0;
    visited[K] = 0;
    for (int i = 1; i < V; i++) {
        int newNode = findShortestNode();
        visited[newNode] = 1;
        updateDist(newNode);
    }
    for (int i = 1; i <= V; i++) {
        if (dist[i] == MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E >> K;
    int u, v, w;
    // for (int i = 1; i <= V; i++) {
    //     for (int j = 1; j <= V; j++) {
    //         graph[i][j] = -1;
    //     }
    // }
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    solve();
}