#include <bits/stdc++.h>
#define pi pair<int, int>
#define ll long long
#define PQ priority_queue
using namespace std;

int N = 0, M = 0, K = 0;
string s, t;

int solve(int i, int j) {
    int cnt = 0;
    if (s[i] == t[j]) {
        cnt = solve(i + 1, j + 1);
        return cnt;
    }
    for (int k = i; k < t.length(); k++) {
        if (s[i] == t[k]) {
            cnt = solve(i + 1, k);
        }
    }
    cnt = solve(i + 1, j);
}

int main(void) {
    int cnt = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        cnt = max(solve(i, 0), cnt);
    }
}