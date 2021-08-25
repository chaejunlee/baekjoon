#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

#define INF 1000000000

using namespace std;

int N, M, X;
vector<pair<int, int> > arr[1001];
int dist[1001];
int res[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > q;
    q.push({0, start});
    
    for (int i = 1; i <= N; i++) {
        if (start == i) dist[i] = 0;
        else dist[i] = INF;
    }
    
    while (!q.empty()) {
        int cost = -q.top().first;
        int u = q.top().second;
        q.pop();
        
        // 요거 살짝 공감 안 감.
        if (cost > dist[u]) continue;
        
        for (auto a : arr[u]) {
            int v = a.first;
            int D = a.second + dist[u];
            
            if (dist[v] > D) {
                dist[v] = D;
                q.push({-D, v});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int u,v,weight;
        cin >> u >> v >> weight;
        arr[u].push_back({v, weight});
    }
    
    memset(res, 0, sizeof(res));
    
    for (int i = 1; i <= N; i++) {
        dijkstra(i);
        res[i] = dist[X];
    }
    res[X] = 0;
    dijkstra(X);
    for (int i = 1; i <= N; i++) {
        res[i] += dist[i];
    }
    sort(res, res + N + 1);
    cout << res[N] << "\n";
    
    
    return 0;
}
