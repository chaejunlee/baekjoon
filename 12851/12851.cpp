#include <bits/stdc++.h>
using namespace std;

int N, M;
int visited[100001];
int CNT = 0, RET = 0;

void solve(int n, int m) {
    queue<int> q;
    q.push(n);
    
    if (n == m) {
        CNT = 0;
        RET = 1;
        return;
    }
    
    int cnt = 0;
    while (CNT == 0) {
        queue<int> p = q;
        q = queue<int>();
        while (!p.empty()) {
            int k = p.front();
            p.pop();
            
            visited[k] = 1;
            
            int a = k - 1;
            int b = k + 1;
            int c = k * 2;
            
            if (a == m) {
                CNT = cnt + 1;
                RET++;
            }
            if (b == m) {
                CNT = cnt + 1;
                RET++;
            }
            if (c == m) {
                CNT = cnt + 1;
                RET++;
            }
            
            if (a >= 0 && !visited[a]) q.push(a);
            if (b <= 100000 && !visited[b]) q.push(b);
            if (c <= 100000 && !visited[c]) q.push(c);
        }
        cnt++;
    }
    return;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    solve(N, M);
    cout << CNT << "\n" << RET << "\n";
    
    return 0;
}
