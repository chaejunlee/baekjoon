#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N, M;
vector<pair<int, int> > bus[1001];
int s, e;
int dist[1001];
int path[1001];

int main(void) {
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }
    cin >> s >> e;
    
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[s] = 0;
    
    priority_queue<pair<int, int> > q;
    q.push({0, s});
    
    while (!q.empty()) {
        int curDist = -q.top().first;
        int here = q.top().second;
        q.pop();
        
        if (curDist > dist[here]) continue;
        
        for (auto v : bus[here]) {
            int next = v.first;
            int nextDist = v.second;
            
            if (dist[next] > dist[here] + nextDist) {
                dist[next] = dist[here] + nextDist;
                //cout << here << " " << next << " " << dist[next] << "\n";
                path[next] = here;
                q.push({-dist[next], next});
            }
        }
    }
    cout << dist[e] << "\n";
    
    stack<int> ret;
    int cnt = 0;
    
    for (int i = e; i != 0; i = path[i]) {
        cnt++;
        ret.push(i);
    }
    
    cout << cnt << "\n";
    
    while (!ret.empty()) {
        cout << ret.top() << " ";
        ret.pop();
    }
    cout << "\n";
    
    return 0;
}
