#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[100001];
int depth[100001];
int parent[100001][20];
int max_depth = 0;

void makeParent(int root) {
    if (adj[root].size() == 0) return;
    for (int a : adj[root]) {
        if (depth[a] == -1) {
            depth[a] = depth[root] + 1;
            //max_depth = max(max_depth, depth[a]);
            parent[a][0] = root;
            makeParent(a);
        }
    }
}

void calParent() {
    for (int k = 1; k <= max_depth; k++) {
        for (int i = 2; i <= N; i++) {
            if (parent[i][k - 1] != 0) {
                parent[i][k] = parent[parent[i][k - 1]][k - 1];
            }
        }
    } 
}

int LCA(int a, int b) {
    if (depth[a] != depth[b]) {
        if (depth[a] < depth[b]) swap(a, b);
        
        int dif = depth[a] - depth[b];
    
        for (int i = 0; dif > 0; i++) {
            if (dif % 2 == 1) {
                a = parent[a][i];
            }
            dif /= 2;
        }
    }
    
    if (a != b) {
        for (int k = max_depth; k >= 0; k--) {
            if (parent[a][k] != 0 && parent[a][k] != parent[b][k]) {
                a = parent[a][k];
                b = parent[b][k];
            }
        }
        
        a = parent[a][0];
    }
    
    return a;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int a, b;
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    parent[1][0] = 0;

    makeParent(1);
    
    int temp = N, cnt = 0;
    while (temp > 1) {
        temp /= 2;
        cnt++;
    }
    max_depth = cnt;

    calParent();
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
    
    return 0;
}
