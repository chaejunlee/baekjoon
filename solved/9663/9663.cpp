#include <bits/stdc++.h>
#define pi pair<int, int>
#define ll long long
#define PQ priority_queue
using namespace std;

int t = 0, N = 0, M = 0, K = 0;
int col[16] = {0};
int cnt = 0;

int promising(int i) {
    int k;
    int check;
    k = 1;
    check = 1;
    while (k < i && check) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            check = 0;
        k++;
    }
    return check;
}

void solve(int i) {
    if (promising(i)) {
        if (i == N) {
            cnt++;
        } else {
            for (int j = 1; j <= N; j++) {
                col[i + 1] = j;
                solve(i + 1);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    solve(0);
    cout << cnt;
}