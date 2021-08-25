#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

#define INF 1000000000

using namespace std;

int N, M, X;
int adj[1001][1001];
int res[1001];

void floyd() {
    for (int i = 1; i <= N; i++) adj[i][i] = 0;
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (adj[i][k] == INF) continue;
            for (int j = 1; j <= N; j++) {
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> X;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            adj[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        int u,v,weight;
        cin >> u >> v >> weight;
        adj[u][v] = weight;
    }
    
    floyd();
    memset(res, 0, sizeof(res));
    
    for (int i = 1; i <= N; i++) {
        res[i] = adj[i][X] + adj[X][i];
    }
    sort(res, res + N + 1);
    cout << res[N] << "\n";
    
    
    return 0;
}
