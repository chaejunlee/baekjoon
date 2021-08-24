#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

#define INF 1000000000

using namespace std;

int N, M;
vector<pair<int, int> > bus[1001];
int A, B;
int dist[1001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u,v,weight;
        cin >> u >> v >> weight;
        bus[u].push_back({v, weight});
    }
    cin >> A >> B;
    
    priority_queue<pair<int, int> > q;
    q.push({0, A});
    
    for (int i = 1; i <= N; i++) {
        if (A == i) dist[i] = 0;
        else dist[i] = INF;
    }
    
    while (!q.empty()) {
        int cost = -q.top().first;
        int u = q.top().second;
        q.pop();
        
        // 요거 살짝 공감 안 감.
        if (cost > dist[u]) continue;
        
        for (auto a : bus[u]) {
            int v = a.first;
            int D = a.second + dist[u];
            
            if (dist[v] > D) {
                dist[v] = D;
                q.push({-D, v});
            }
        }
    }
    cout << dist[B] << "\n";
    
    
    return 0;
}
