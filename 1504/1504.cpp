#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

#define INF 987654321

using namespace std;

int N, E, v1, v2;
vector<pair<int, int> > adj[801];
int dist[801];

void dijkstra(int start) {

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    
    priority_queue<pair<int, int> > q;
    q.push({0, start});
    
    while (!q.empty()) {
        int here = q.top().second;
        int cost = -q.top().first;
        q.pop();
        
        if (dist[here] < cost) continue;
        
        for (auto v : adj[here]) {
            int next = v.first;
            int nextDist = cost + v.second;
            
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                q.push({-nextDist, next});
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> E;
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin >> v1 >> v2;
    
    dijkstra(1);
    long long one_v1 = dist[v1];
    long long one_v2 = dist[v2];
    
    dijkstra(v1);
    long long v1_v2 = dist[v2];
    long long v1_N = dist[N];
    
    dijkstra(v2);
    long long v2_v1 = dist[v1];
    long long v2_N = dist[N];
    
    long long a = one_v1 + v1_v2 + v2_N;
    long long b = one_v2 + v2_v1 + v1_N;
    
    // cout << a <<" "<< b;
    long long res = min(a, b);
    
    if (res >= INF) cout << "-1\n";
    else cout << res << "\n";
    
    return 0;
}
