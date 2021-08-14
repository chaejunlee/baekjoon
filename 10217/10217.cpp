#include <bits/stdc++.h>
#define MAX 10000001
using namespace std;

int T, N, M, K;
vector<pair<int, pair<int, int> > > adj[101];
int cache[101][10001];

int solve(int start) {
    priority_queue<pair<int, pair<int, int> > > pq;
    
    cache[start][0] = 0;
    pq.push({0, {start, 0}});
    
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int here = pq.top().second.first;
        int cost = pq.top().second.second;
        //cout << dist << " " << here << " " << cost << "\n";
        pq.pop();
        
        if (dist > cache[here][cost]) continue;
        
        for (auto there : adj[here]) {
            int there_dist = -there.first;
            int there_cost = there.second.second;
            int there_v = there.second.first;
            
            int money = there_cost + cost;
            int distance = dist + there_dist;
            
            if (money > M) continue;
            
            if (distance < cache[there_v][money]) {
                cache[there_v][money] = distance;
                pq.push({-distance, {there_v, money}});
                
            }
        }
    }
    
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                cache[i][j] = MAX;
            }
        }
        
        for (int i = 1; i <= N; i++) adj[i].clear();
        for (int i = 0; i < K; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u].push_back({-d, {v, c}});
        }
        solve(1);
        int res = MAX;
        for (int i = 0; i <= M; i++) {
            //cout << cache[N][i] << "\n";
            if (res > cache[N][i]) {
                res = cache[N][i];
            }
            
        }
        (res == MAX) ? cout << "Poor KCM\n" : cout << res << "\n";
    }
    
    
    
    return 0;
}
