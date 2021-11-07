#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[32001];
int indegree[32001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        
        cout << i << " ";
        
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]--;
            if (indegree[adj[i][j]] == 0) q.push(adj[i][j]);
        }
    }
    cout << "\n";
    return 0;
}
