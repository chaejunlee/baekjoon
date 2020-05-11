#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> PAIR; // idx, dist
int V;
int d = 0;
vector<PAIR> edge[100003];
bool isVisited[100003];
int longestChild(int root) {
    int max1 = 0;
    int max2 = 0;
    for (auto child : edge[root]) {
        if (isVisited[child.X])
            continue;
        isVisited[child.X] = true;
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
    cin >> V;
    for (int i = 0; i < V; i++) {
        int v;
        cin >> v;
        while (true) {
            int a;
            cin >> a;
            if (a == -1)
                break;
            else {
                int b;
                cin >> b;
                edge[v].push_back({a, b});
            }
        }
    }
    isVisited[1] = true;
    longestChild(1);
    cout << d;
}