#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> PAIR;
vector<PAIR> tree[10001];
bool visited[10001];
int d = 0;
int N;
int longestChild(int root) {
    int max1 = 0, max2 = 0;
    for (auto child : tree[root]) {
        if (visited[child.X])
            continue;
        visited[child.X] = true;
        int dist = longestChild(child.X) + child.Y;
        if (dist > max1) {
            max2 = max1;
            max1 = dist;
        }
        else if (dist > max2)
            max2 = dist;
    }
    d = max(d, max1 + max2);
    return max1;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
    }
    visited[1] = true;
    longestChild(1);
    cout << d;
    return 0;
}