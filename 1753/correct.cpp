#include <bits/stdc++.h>
using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int dist[20001] = {0};
const int MAX = INT_MAX;

void solve() {
    for (int i = 1; i <= V; i++) {
        dist[i] = MAX;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push(make_pair(0, K));
    dist[K] = 0;
    
    while (!PQ.empty()) {
        int cost = PQ.top().first;
        int curr = PQ.top().second;
        PQ.pop();

        for (auto v : graph[curr]) {
            int next = v.first;
            int nCost = v.second;

            if (dist[next] > cost + nCost) {
                dist[next] = cost + nCost;
                PQ.push(make_pair(dist[next], next));
            }
        }
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