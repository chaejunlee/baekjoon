#include <bits/stdc++.h>
using namespace std;

vector<int> *v;
int *visited;

void dfs(int parent) {
    for (int i = 0; i < v[parent].size(); i++) {
        if (visited[v[parent][i]] == 0) {
            visited[v[parent][i]] = parent;
            dfs(v[parent][i]);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0, nodeA = 0, nodeB = 0;
    cin >> n;
    v = new vector<int>[n + 1]();
    visited = new int[n + 1]();

    visited[1] = 1;
    for (int i = 1; i < n; i++) {
        cin >> nodeA >> nodeB;
        v[nodeA].push_back(nodeB);
        v[nodeB].push_back(nodeA);
    }
    
    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << visited[i] << "\n";
    }
    return 0;
}