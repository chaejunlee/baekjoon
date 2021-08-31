#include <bits/stdc++.h>
using namespace std;

int A, B;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;
    
    queue<int> q;
    q.push(A);
    
    int turn = 0;
    while (!q.empty()) {
        queue<int> p = q;
        q = queue<int>();
        while (!p.empty()) {
            long long a = (long long) p.front();
            p.pop();
            
            //cout << a << " " << turn << "\n";
            
            if (a == B) {
                cout << turn + 1 << "\n";
                return 0;
            }
            
            long long x = a * 2;
            long long y = a * 10 + 1;
            
            if (x <= B) q.push(x);
            if (y <= B) q.push(y);
        }
        turn++;
    }
    cout << "-1\n";
    
    return 0;
}
