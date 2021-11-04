#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0, nodeA = 0, nodeB = 0;
    cin >> n;
    stack<int> s;
    
    int *parent = new int[n + 1]();
    parent[0] = 1;
    parent[1] = 1;
    for (int i = 1; i < n; i++) {
        cin >> nodeA >> nodeB;
        if (nodeA == 1) {
            int ptr = nodeB;
            if (parent[nodeB]) {
                while (parent[parent[ptr]] != ptr) {
                    s.push(ptr);
                    ptr = parent[ptr];
                }
                while (!s.empty()) {
                    int top = s.top();
                    s.pop();
                    parent[ptr] = top;
                    ptr = top;
                }
            }
            parent[ptr] = nodeA;
        }
        else if (nodeB == 1) {
            int ptr = nodeA;
            if (parent[nodeA]) {
                while (parent[parent[ptr]] != ptr) {
                    s.push(ptr);
                    ptr = parent[ptr];
                }
                while (!s.empty()) {
                    int top = s.top();
                    s.pop();
                    parent[ptr] = top;
                    ptr = top;
                }
            }
            parent[ptr] = nodeB;
        }
        else if (!parent[nodeA]) {
            if (!parent[nodeB]) {
                parent[nodeA] = nodeB;
                parent[nodeB] = nodeA;
            }
            parent[nodeA] = nodeB;
        }
        else {
            parent[nodeB] = nodeA;
        }

    }
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}