#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void print(int k, int n, int m) {
    if (m == 0) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = k + 1; i <= n - m + 1; i++) {
        v.push_back(i);
        print(i, n, m - 1);
        v.pop_back();
    }
}

void solve(int n, int m) {
    for (int i = 1; i <= n - m + 1; i++) {
        v.push_back(i);
        print(i, n, m - 1);
        v.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    solve(n, m);
}