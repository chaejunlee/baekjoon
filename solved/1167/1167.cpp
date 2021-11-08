#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> *v;
int visited[100001];
int n = 0;
int radius = 0;
queue<int> q;

int dfs(int x) {
    visited[x] = 1;
    int maxR = 0;
    for (int i = 0; i < v[x].size(); i++) {
        int next = v[x][i].first;
        if (!visited[next]) {
            int temp = v[x][i].second + dfs(next);
            maxR = max(maxR, temp);
        }
        // cout << "a: " << x << " b: " << next << " r: " << maxR << "\n";
    }
    return maxR;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v = new vector<pair<int, int>>[n + 1]();
    for (int i = 0; i < n; i++) {
        int start = 0, end = 0, weight = 0;
        cin >> start;
        cin >> end;
        while (end != -1) {
            cin >> weight;
            v[start].push_back(make_pair(end, weight));
            // cout << "v: " << start << " u: " << end << " w: " << weight << "\n";
            cin >> end;
        }
    }
    // cout << "input ok" << '\n';
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int temp = dfs(i);
        radius = max(temp, radius);
    }
    cout << radius;

    return 0;
}